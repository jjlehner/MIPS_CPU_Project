#!/bin/bash
rm -rf test/bin1
rm -rf test/bin1/r_type
rm -rf test/bin1/i_type
rm -rf test/bin1/j_type
rm -rf test/tmp1
rm -rf test/tmp1/r_type
rm -rf test/tmp1/i_type
rm -rf test/tmp1/j_type
rm -rf test/hex1
rm -rf test/hex1/r_type
rm -rf test/hex1/i_type
rm -rf test/hex1/j_type
rm -rf test/results1
rm -rf test/simulator1

mkdir -p test/bin1
mkdir -p test/bin1/r_type
mkdir -p test/bin1/i_type
mkdir -p test/bin1/j_type
mkdir -p test/tmp1
mkdir -p test/tmp1/r_type
mkdir -p test/tmp1/i_type
mkdir -p test/tmp1/j_type
mkdir -p test/hex1
mkdir -p test/hex1/r_type
mkdir -p test/hex1/i_type
mkdir -p test/hex1/j_type
mkdir -p test/results1
mkdir -p test/simulator1

### get file input 

SOURCEDIR="$1"
INSTRUCTION="$2"

lower_level=("${SOURCEDIR}/mips_cpu_*.v"
	"${SOURCEDIR}/mips_cpu/*.v"
	)

if [ -z "$INSTRUCTION" ]; then
	touch test/results1/result1.csv
	>&2 echo "Instruction has not been specified. Proceeding with all functional tests."
	for type in r i j e s ; do
		TESTS="test/tests/${type}_type/*.s"

		>&2 echo "Commencing ${type} type instruction tests."	
		echo "${type} tests:" >> test/results1/result1.csv

		for t in $TESTS; do
			TESTCASE="$t"
			basename "$TESTCASE"
			hexname="$(basename -- $TESTCASE)"
			hexed="${hexname%.*}"
			exec 5< $t	

			### first line specifies what is being tested
			read -r line <&5
			testType="${line:1:${#line}-1}"

			### gives the expected value
			read -r line <&5
			expectedValue="${line:1:${#line}-1}"

			### read test id
			read -r line <&5
			testId="${line:1:${#line}-1}"

			### read additional comment
			read -r line <&5
			comment="${line:1:${#line}-1}"

			### assemble input file
			mipsel-linux-gnu-gcc -c test/tests/${type}_type/$hexed.s -o test/tmp1/${type}_type/$hexed.o
		
			mipsel-linux-gnu-objcopy -O binary --only-section=.text test/tmp1/${type}_type/$hexed.o test/bin1/${type}_type/$hexed.bin
		
			hexdump -v test/bin1/${type}_type/$hexed.bin > test/hex1/${type}_type/$hexed.hex.txt -e '1/4 "%08x " "\n"'
			
			###compile testbench
			iverilog -g 2012 \
				test/mips_cpu_bus_tb_delay1.v test/RAM_32x2048_delay1.v ${lower_level[@]} -s mips_cpu_bus_tb_delay1 -Pmips_cpu_bus_tb_delay1.RAM_INIT_FILE=\"test/hex1/${type}_type/$hexed.hex.txt\" -o test/simulator1/mips_cpu_bus_tb_delay1_$hexed 2>/dev/null

			###run testbench
			set +e
			test/simulator1/mips_cpu_bus_tb_delay1_$hexed > test/results1/mips_cpu_bus_tb_delay1_$hexed.txt
			output=$(tail -n 1 test/results1/mips_cpu_bus_tb_delay1_${hexed}.txt)
			echo "out $output"
			echo "exp $expectedValue"
			set -e

			###testing for failure code
			# if [[ "${output}" -ne 0 ]]; then
			# 	echo "${testType}_${testId} "fail" ${output}" >> test/results1/result1_${INSTRUCTION}.csv
			# fi

		
			###compare output to expected
			bool="fail"
			if [ $output -eq $expectedValue ]; then
				bool="pass"
			fi

			echo "${testType}_${testId} ${bool} ${comment}" >> test/results1/result1.csv
			echo ""

		done
	done


else
	for type in r i j e s ; do
		TESTS="test/tests/${type}_type/*.s"
		touch test/results1/result1_${INSTRUCTION}.csv
		>&2 echo "Instruction has been specified. Proceeding with ${INSTRUCTION} test."

		for t in $TESTS; do
			TESTCASE="$t"
			basename "$TESTCASE" >/dev/null
			hexname="$(basename -- $TESTCASE)"
			hexed="${hexname%.*}"
			exec 5< $t

			### first line specifies what is being tested
			read -r line <&5
			testType="${line:1:${#line}-1}"

			### gives the expected value
			read -r line <&5
			expectedValue="${line:1:${#line}-1}"

			### read test id
			read -r line <&5
			testId="${line:1:${#line}-1}"

			### read additional comment
			read -r line <&5
			comment="${line:1:${#line}-1}"

			if [ "$testType" == "$INSTRUCTION" ]; then
		
				### assemble input file
				mipsel-linux-gnu-gcc -c test/tests/${type}_type/$hexed.s -o test/tmp1/${type}_type/$hexed.o
			
				mipsel-linux-gnu-objcopy -O binary --only-section=.text test/tmp1/${type}_type/$hexed.o test/bin1/${type}_type/$hexed.bin
			
				hexdump -v test/bin1/${type}_type/$hexed.bin > test/hex1/${type}_type/$hexed.hex.txt -e '1/4 "%08x " "\n"'
				
				###compile testbench
				iverilog -g 2012 \
					test/mips_cpu_bus_tb_delay1.v test/RAM_32x2048_delay1.v ${lower_level[@]} -s mips_cpu_bus_tb_delay1 -Pmips_cpu_bus_tb_delay1.RAM_INIT_FILE=\"test/hex1/${type}_type/$hexed.hex.txt\" -o test/simulator1/mips_cpu_bus_tb_delay1_$hexed 2>/dev/null

				###run testbench
				set +e
				test/simulator1/mips_cpu_bus_tb_delay1_$hexed > test/results1/mips_cpu_bus_tb_delay1_$hexed.txt
				output=$(tail -n 1 test/results1/mips_cpu_bus_tb_delay1_${hexed}.txt)
				echo "out $output"
				echo "exp $expectedValue"
				set -e

				###testing for failure code
				# if [[ "${output}" -ne 0 ]]; then
				# 	echo "${testType}_${testId} "fail" ${output}" >> test/results1/result1_${INSTRUCTION}.csv
				# fi

			
				###compare output to expected
				bool="fail"
				if [ $output -eq $expectedValue ]; then
					bool="pass"
				fi

				echo "${testType}_${testId} ${bool} ${comment}" >> test/results1/result1_${INSTRUCTION}.csv
				echo ${bool}
				echo ""
			fi

		done
	done

fi


