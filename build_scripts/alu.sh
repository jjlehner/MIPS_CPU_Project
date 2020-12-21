#!/bin/bash
set -e

cd ../src
verilator -Wall -cc ALU.v -prefix ALU --Mdir ../test/ALU_tb --exe ../test/tb_src/ALU_testbench.cpp
cd ../test/ALU_tb
make -f ALU.mk ALU > /dev/null
./ALU
