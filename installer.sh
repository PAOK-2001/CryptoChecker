#!/bin/bash 
dir="/usr/local/bin" #Replace with your PATH directory
src="$PWD/CryptoChecker.cpp"
destiny="CryptoChecker"
# Compile SRC
g++ -std=c++11 $src -o $destiny $(pkg-config --cflags --libs curlpp) -fPIE
# Move file to PATH
sudo mv $destiny $dir