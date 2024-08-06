#! /bin/zsh

# otool -l $(which protoc)

git clone https://github.com/abseil/abseil-cpp.git
mkdir build/ && cd build
cmake -DABSL_BUILD_TESTING=ON -DABSL_USE_GOOGLETEST_HEAD=ON -DCMAKE_CXX_STANDARD=14 ..
cmake --build . --target all
cmake --install .

git clone https://github.com/protocolbuffers/protobuf.git
cd protobuf
git submodule update --init --recursive
cmake --build .
cmake --install .