#!/bin/bash
set -e

cd ../src
verilator -Wall -cc Program_Counter.v -prefix Program_Counter --Mdir ../test/Program_Counter_tb --exe ../test/tb_src/Program_Counter_testbench.cpp
cd ../test/Program_Counter_tb
make -f Program_Counter.mk Program_Counter > /dev/null
./Program_Counter
