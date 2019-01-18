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
echo "#### Testing... ####"
tests/tests
popd
