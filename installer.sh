#!/bin/bash 
dir="/usr/local/bin"
src="$PWD/CryptoChecker.cpp"
destiny="CryptoChecker"
# Compile SRC
g++ $src -o $destiny pkg-config --cflags --libs curlpp
# Move file to PATH
sudo mv $destiny $dir