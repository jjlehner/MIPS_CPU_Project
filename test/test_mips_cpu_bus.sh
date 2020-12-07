#!/bin/bash

mkdir -p bin/assembler1
mkdir -p test/hex1
mkdir -p test/results1
mkdir -p test/simulator1

### get file input 

SOURCEDIR = "$1"
INSTRUCTION = "$2"

if ["${INSTRUCTION}" -eq 0]
then
	touch test/results1/result1.csv
	>&2 echo "Instruction has not been specified. Proceeding with all functional tests."

	TESTS = "test/tests/*.asm.txt"
	for t in TESTS; do
		TESTCASE = "$t"
		exec 5< $t

		### first line specifies what is being tested
		read -r line <&5
		testType = "${line:1:${#line}-1}"

		### gives the expected value
		read -r line <&5
		expectedValue = "${line:1:${#line}-1}"

		### read test id
		read -r line <&5
		testId = "${line:1:${#line}-1}"
		### read additional comment
		read -r line <&5
		comment = "${line:1:${#line}-1}"

		### assemble input file
		bin/assembler <test/tests/${TESTCASE}.asm.txt > test/hex1/${TESTCASE}.hex.txt

		###compile testbench
		iverilog -g 2012 \
			${SOURCEDIR}/mips_cpu.v test/mips_cpu_bus_tb_delay1.v/RAM_32x2048_delay1.v \
			-s mips_cpu_bus_tb_delay1 \
			-Pmips_cpu_bus_tb_delay1.RAM_INIT_FILE=\ "test/hex1/${TESTCASE}.hex.txt" \
			-o test/simulator1/mips_cpu_bus_tb_delay1_${TESTCASE}

		###run testbench
		set +e
		test/simulator1/mips_cpu_bus_tb_delay1_${testType} > test/results1/mips_cpu_bus_tb_delay1_${testType}.stdout
		output = $?
		set -e

		###testing for failure code
		if [[ "${output}" -ne 0 ]]; then
			echo "${testType}_${testId} "fail" ${output}" >> test/results1/result1.csv
		fi

	
		###compare output to expected
		bool = "fail"
		if [$output -eq $expectedValue]; then
			bool = "pass"
		fi

		echo "${testType}_${testId} ${bool} ${comment}" >> test/results1/result1.csv

	done



else
	touch test/results1/result1_${INSTRUCTION}.csv
	>&2 echo "Instruction has been specified. Proceeding with ${INSTRUCTION} test."
	TESTS = "test/tests/*.asm.txt"
	for t in TESTS; do
		TESTCASE = "$t"
		exec 5< $t

		### first line specifies what is being tested
		read -r line <&5
		testType = "${line:1:${#line}-1}"

		### gives the expected value
		read -r line <&5
		expectedValue = "${line:1:${#line}-1}"

		### read test id
		read -r line <&5
		testId = "${line:1:${#line}-1}"
		### read additional comment
		read -r line <&5
		comment = "${line:1:${#line}-1}"

		if [[ "${testType}" -eq "${INSTRUCTION}"]]; then
	
			### assemble input file
			bin/assembler <test/tests/${TESTCASE}.asm.txt > test/hex1/${TESTCASE}.hex.txt

			###compile testbench
			iverilog -g 2012 \
				${SOURCEDIR}/mips_cpu.v test/mips_cpu_bus_tb_delay1.v/RAM_32x2048_delay1.v \
				-s mips_cpu_bus_tb_delay1 \
				-Pmips_cpu_bus_tb_delay1.RAM_INIT_FILE=\ "test/hex1/${TESTCASE}.hex.txt" \
				-o test/simulator1/mips_cpu_bus_tb_delay1_${TESTCASE}

			###run testbench
			set +e
			test/simulator1/mips_cpu_bus_tb_delay1_${testType} > test/results1/mips_cpu_bus_tb_delay1_${testType}.stdout
			output = $?
			set -e

			###testing for failure code
			if [[ "${output}" -ne 0 ]]; then
				echo "${testType}_${testId} "fail" ${output}" >> test/results1/result1_${INSTRUCTION}.csv
			fi

		
			###compare output to expected
			bool = "fail"
			if [$output -eq $expectedValue]; then
				bool = "pass"
			fi

			echo "${testType}_${testId} ${bool} ${comment}" >> test/results1/result1_${INSTRUCTION}.csv
		fi

	done

fi


