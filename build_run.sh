#!/bin/bash
cmake --build ./cmake-build-debug --target all -- -j 9
cmake-build-debug/runpix log4cxx.config

