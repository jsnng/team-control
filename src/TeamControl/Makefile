all: receiver

receiver: SSL_Receiver.h SSL_Receiver.cpp
	clang++ -std=c++20 -o build/receiver.o SSL_Receiver.cpp

clean:
	rm -f receiver *~