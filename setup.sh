#! /bin/zsh

# brew install protobuf

git clone https://github.com/protocolbuffers/protobuf.git
cd protobuf
git submodule update --init --recursive
cmake . -DCMAKE_CXX_STANDARD=20
cmake --build .

git update-index --assume-unchanged .vscode/settings.json
#git update-index --no-assume-unchanged .vscode/settings.json
git update-index --assume-unchanged .vscode/tasks.json
