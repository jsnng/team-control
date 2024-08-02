#! /usr/bin/env bash

if ! command -v protoc &> /dev/null ; then
    brew install protobuf
fi

touch __init__.py

for proto in `ls proto2/*.proto`; do
    protoc -I proto2/ --python_out=. $proto
done

for py in `ls *.py`; do 
    mv $py $py.old
    cat $py.old | sed 's/import ssl/import TeamControl.SSL.ssl/g' > $py
    rm $py.old
done

for py in `ls *.py`; do 
    mv $py $py.old
    cat $py.old | sed 's/import gr/import TeamControl.SSL.gr/g' > $py
    rm $py.old
done

   