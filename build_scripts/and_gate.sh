#!/bin/bash
set -e

cd ../src
verilator -Wall -cc And_Gate.v -prefix And_Gate --Mdir ../test/And_Gate_tb --exe ../test/tb_src/And_Gate_testbench.cpp
cd ../test/And_Gate_tb
make -f And_Gate.mk And_Gate > /dev/null
./And_Gate
