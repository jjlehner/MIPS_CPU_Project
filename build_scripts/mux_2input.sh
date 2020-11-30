#!/bin/bash
set -e

cd ../src
verilator -Wall -cc MUX_2INPUT.v -prefix MUX_2INPUT --Mdir ../test/MUX_2INPUT_tb --exe ../test/tb_src/MUX_2INPUT_testbench.cpp
cd ../test/MUX_2INPUT_tb
make -f MUX_2INPUT.mk MUX_2INPUT > /dev/null
./MUX_2INPUT
