#!/usr/bin/env bash

# Fail if any commands fails
set -e

echo "#### Updating submodules... ####"
git submodule update --init

echo "#### Generating code... ####"
pushd codegen
bin/codegen
popd

echo "#### Building... ####"
mkdir -pv build
pushd build
cmake -DGIT_SUBMODULE=OFF -DCMAKE_BUILD_TYPE=Debug ..
make tests

echo "#### Testing... ####"
tests/tests

popd
