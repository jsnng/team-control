#! /bin/zsh

# brew install protobuf
# brew install swig

git clone https://github.com/protocolbuffers/protobuf.git
cd protobuf
git submodule update --init --recursive
mkdir build/
cd build/
cmake ../ -DCMAKE_CXX_STANDARD=20
cmake --build .

git update-index --assume-unchanged .vscode/settings.json
# git update-index --no-assume-unchanged .vscode/settings.json
git update-index --assume-unchanged .vscode/tasks.json
git update-index --assume-unchanged .vscode/c_cpp_properties.json
