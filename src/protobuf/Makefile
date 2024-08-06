CFLAGS=-I /opt/homebrew/Cellar/protobuf/27.1/include

all: ssl_gc_common_pb

ssl_gc_common_pb: ssl_gc_common.pb.h ssl_gc_common.pb.cc
	clang++ ${CFLAGS} -o ssl_gc_common_pb.o ssl_gc_common.pb.cc -lprotobuf -L /opt/homebrew/Cellar/protoc/27.1/include/