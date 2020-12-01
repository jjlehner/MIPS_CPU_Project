#!/bin/bash
set -e

cd ../src
verilator -Wall -cc Adder.v -prefix Adder --Mdir ../test/Adder_tb --exe ../test/tb_src/adder_testbench.cpp
cd ../test/Adder_tb
make -f Adder.mk Adder > /dev/null
./Adder
