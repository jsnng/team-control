#! /usr/bin/env python3 -B

import socket
import struct

from TeamControl.SSL.proto2 import ssl_gc_referee_message_pb2

vision_ssl = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
vision_ssl.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEPORT, 1)
vision_ssl.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
vision_ssl.bind(('', 10003))
mreq = struct.pack("=4sl", socket.inet_aton("224.5.23.1"), socket.INADDR_ANY)
vision_ssl.setsockopt(socket.IPPROTO_IP, socket.IP_ADD_MEMBERSHIP, mreq)

while True:
    msg, addr = vision_ssl.recvfrom(1024)
    func = ssl_gc_referee_message_pb2.Referee()
    msg = func.FromString(msg)
    print(msg)