iverilog -Wall -g 2012 drive.v Decode_Execute_Register.v -s drive
./a.out
gtkwave out.vcd