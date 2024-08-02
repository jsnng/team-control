#! /usr/bin/env python3 -B

import socket
import struct

from TeamControl.SSL import ssl_vision_wrapper_pb2
from TeamControl.Model.ssl_vision_wrapper_py import SSL_WrapperPacket
import argparse

from google.protobuf import json_format

import logging

class CustomFormatter(logging.Formatter):
    '''logging log object'''
    format = "%(asctime)s: (%(filename)s:%(lineno)d) %(levelname)s - %(message)s"
    FORMATS = {
        logging.DEBUG: "\x1b[38;20m" + format +  "\x1b[0m",
        logging.INFO: "\x1b[38;20m" + format +  "\x1b[0m",
        logging.WARNING: "\x1b[33;20m" + format +  "\x1b[0m",
        logging.ERROR: "\x1b[31;20m" + format +  "\x1b[0m",
        logging.CRITICAL: "\x1b[31;1m" + format +  "\x1b[0m"
    }

    def format(self, record):
        log_fmt = self.FORMATS.get(record.levelno)
        formatter = logging.Formatter(log_fmt)
        return formatter.format(record)
    
custom_fmt = logging.StreamHandler()
custom_fmt.setLevel(logging.DEBUG)
custom_fmt.setFormatter(CustomFormatter())
log = logging.getLogger()
log.setLevel(logging.DEBUG)
log.addHandler(custom_fmt)


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--vision-ssl', action="store_true")

    args = parser.parse_args()
    # print(args)

    vision_multicast_port = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
    vision_multicast_port.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEPORT, 1)
    vision_multicast_port.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
    if getattr(args, 'vision_ssl'):
        vision_multicast_port.bind(('', 10006))
    vision_multicast_port.bind(('', 10020))
    packed_binary_data = struct.pack("=4sl", socket.inet_aton("224.5.23.2"), socket.INADDR_ANY)
    vision_multicast_port.setsockopt(socket.IPPROTO_IP, socket.IP_ADD_MEMBERSHIP, packed_binary_data)

    while True:
        msg, addr = vision_multicast_port.recvfrom(2048)
        func = ssl_vision_wrapper_pb2.SSL_WrapperPacket()
        msg = func.FromString(msg)

        ssl_vision_wrapper_packet = json_format.MessageToDict(msg)
        # print(ssl_vision_wrapper_packet)
        wrapper_packet = SSL_WrapperPacket(**ssl_vision_wrapper_packet)
        # print(ssl_vision_wrapper_dict)
        break