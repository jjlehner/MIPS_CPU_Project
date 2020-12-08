#!/bin/bash

mkdir -p bin/assembler1
mkdir -p test/hex1
mkdir -p test/results1
mkdir -p test/simulator1
touch test/results1/result1.csv
### get file input 

TESTS = "test/tests/*.s"
for t in TESTS; do
	TESTCASE = "$t"
	exec 2< $t

### first line specifies what is being tested
	read -r line <&2
	testType = "${line:1:${#line}-1}"

### gives the expected value
	read -r line <&2
	expectedValue = "${line:1:${#line}-1}"


### assemble input file
	bin/assembler <test/tests/${TESTCASE}.asm.txt > test/hex1/${TESTCASE}.hex.txt

###compile testbench
	iverilog -g 2012 \
		src/mips_cpu.v test/mips_cpu_bus_tb_delay1.v/RAM_32x2048_delay1.v \
		-s mips_cpu_bus_tb_delay1 \
		-Pmips_cpu_bus_tb_delay1.RAM_INIT_FILE=\ "test/hex1/${testType}.hex.txt" \
		-o test/simulator1/mips_cpu_bus_tb_delay1_${testType}

###run testbench
	set +e
	test/simulator1/mips_cpu_bus_tb_delay1_${testType} > test/results1/mips_cpu_bus_tb_delay1_${testType}.stdout
	output = $?
	set -e

###compare output to expected
	bool = "fail"
	if [$output -eq $expectedValue]; then
		bool = "pass"
	fi

	echo "$testType, $expectedValue, $output" >> test/results1/result1.csv

done
