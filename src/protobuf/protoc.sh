#! /bin/zsh

for proto in `ls proto2/*.proto`; do
    protoc -I proto2/ --cpp_out=. ./$proto
done