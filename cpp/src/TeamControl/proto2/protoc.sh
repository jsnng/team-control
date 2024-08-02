#! /bin/zsh

for proto in `ls *.proto`; do
    protoc --cpp_out=. ./$proto
done