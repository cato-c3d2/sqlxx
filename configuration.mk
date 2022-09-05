# CXX = g++
  CXX = clang++

# CXX_VERSION = c++11
# CXX_VERSION = c++14
  CXX_VERSION = c++17

CXXFLAGS = -std=$(CXX_VERSION) -Wall -g3
SHELL    = /bin/bash
