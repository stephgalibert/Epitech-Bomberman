#!/bin/bash
echo "##### Building the project using cmake... #####"
mkdir build && cd build && cmake ..
echo "##### Start compilation... #####"
make
echo "##### Installing the project in bin folder... #####"
make install && cd ..
echo "##### Installation successful ! #####"
