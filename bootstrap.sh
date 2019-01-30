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
cmake -H. -Bbuild -DHUNTER_STATUS_DEBUG=ON -DCMAKE_BUILD_TYPE=Debug -DGIT_SUBMODULE=OFF
make -C build tests

echo "#### Testing... ####"
build/tests/tests
