#!/bin/bash

cd "$(dirname "$0")"
cd ../src
verilator -Wall -cc Register_File.v --prefix Register_File_tb --Mdir ../test/Register_File_obj_dir --exe flopr_tb.cpp -CFLAGS "-std=c++17"
cd obj_dir
make -j4 -f Reg_Test.mk Reg_Test

./Reg_Test