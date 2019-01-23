#!/bin/bash

echo "#### Generating code... ####"
pushd codegen
bin/codegen
popd

echo "#### Building... ####"
mkdir -pv build
pushd build
cmake ..
make tests
if [ $? -eq 0 ]
then
    echo "#### Testing... ####"
    tests/tests
else
    echo "#### Build failed ####"
fi
popd
