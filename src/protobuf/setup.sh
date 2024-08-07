#! /bin/zsh

git clone https://github.com/protocolbuffers/protobuf.git
cd protobuf
git submodule update --init --recursive
cmake --build . --target all
cmake --install .