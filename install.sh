#!/bin/bash
echo "##### Building the project using cmake... #####"
BUILD=build
if [ ! -d "$BUILD" ]; then
  mkdir build
  # Control will enter here if $DIRECTORY doesn't exist.
fi
cd build && cmake -DCMAKE_INSTALL_PREFIX:PATH=../bin ..
echo "##### Start compilation... #####"
make
echo "##### Installing the project in ./bin folder... #####"
make install
echo "##### Installation successful ! #####"
