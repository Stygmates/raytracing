# Raytracing project [![Build Status](https://travis-ci.org/Stygmates/raytracing.svg?branch=master)](https://travis-ci.org/Stygmates/raytracing)

## Introduction

This is a group project for one of our courses, which presents the concept of raytracing, using a grid to store the triangles and the Digital Differential Analyzer Algorithm to find the slots of the grid to scan, more features are coming, such as Phong lighting, and stochastic raytracing.

## Building instructions

  - Add necessary repos:

  ```
  sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
  - sudo apt-get update -qq
  ```
  - Install dependencies
  ```
  sudo apt-get install -qq g++-6 build-essential qtcreator libqt5opengl5 libqt5opengl5-dev gdb
  ```
  
  - Use gcc6 compiler
  ```
  sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-6 90
  ```
  - This project uses the googletest framework for its unit testing, it can be installed with:

  ```
  (git clone https://github.com/google/googletest && cd googletest/googletest && mkdir build && cd build && cmake .. && make)
  ```

  - Generate the makefile:
  ```
  qmake
  ```
  - Compile the project:
  ```
  make -f Makefile.Release
  ```
  # Execute
  ```
  ./bin/raytracing
  ```