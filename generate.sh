#!/bin/bash
cmake -S . -B build/ -DCMAKE_C_COMPILER=/opt/homebrew/bin/gcc-13 -DCMAKE_BUILD_TYPE=Debug
#cmake -S . -B build/ -DCMAKE_BUILD_TYPE=Debug
