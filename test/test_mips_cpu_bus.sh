#!/bin/bash
rm -rf bin1
rm -rf bin1/r_type
rm -rf bin1/i_type
rm -rf bin1/j_type
rm -rf tmp1
rm -rf tmp1/r_type
rm -rf tmp1/i_type
rm -rf tmp1/j_type
rm -rf hex1
rm -rf hex1/r_type
rm -rf hex1/i_type
rm -rf hex1/j_type
rm -rf results1
rm -rf simulator1

mkdir -p bin1
mkdir -p bin1/r_type
mkdir -p bin1/i_type
mkdir -p bin1/j_type
mkdir -p tmp1
mkdir -p tmp1/r_type
mkdir -p tmp1/i_type
mkdir -p tmp1/j_type
mkdir -p hex1
mkdir -p hex1/r_type
mkdir -p hex1/i_type
mkdir -p hex1/j_type
mkdir -p results1
mkdir -p simulator1

### get file input 

SOURCEDIR="$1"
INSTRUCTION="$2"

lower_level=(../"${SOURCEDIR}/mips_cpu_*.v"
	"../${SOURCEDIR}/mips_cpu/*.v"
	)
cd "$(dirname "$0")"
if [ -z "$INSTRUCTION" ]; then
	i=1
	touch results1/result1.csv
	#>&2 echo "Instruction has not been specified. Proceeding with all functional tests."
	for type in r i j ; do
		TESTS="tests/${type}_type/*.s"

		#>&2 echo "Commencing ${type} type instruction tests."	
		echo "${type} tests:" >> results1/result1.csv

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

			### assemble input file
			mipsel-linux-gnu-gcc -c tests/${type}_type/$hexed.s -o tmp1/${type}_type/$hexed.o &>/dev/null
		
			mipsel-linux-gnu-objcopy -O binary --only-section=.text tmp1/${type}_type/$hexed.o bin1/${type}_type/$hexed.bin
		
			hexdump -v bin1/${type}_type/$hexed.bin > hex1/${type}_type/$hexed.hex.txt -e '1/4 "%08x " "\n"'
			
			###compile testbench
			iverilog -g 2012 \
				mips_cpu_bus_tb_delay1.v RAM_32x2048_delay1.v ${lower_level[@]} -s mips_cpu_bus_tb_delay1 -Pmips_cpu_bus_tb_delay1.RAM_INIT_FILE=\"hex1/${type}_type/$hexed.hex.txt\" -o simulator1/mips_cpu_bus_tb_delay1_$hexed 2>/dev/null

			###run testbench
			set +e
			simulator1/mips_cpu_bus_tb_delay1_$hexed > results1/mips_cpu_bus_tb_delay1_$hexed.txt
			output=$(tail -n 1 results1/mips_cpu_bus_tb_delay1_${hexed}.txt)
			#echo "out $output"
			#echo "exp $expectedValue"
			set -e

			###testing for failure code
			# if [[ "${output}" -ne 0 ]]; then
			# 	echo "${testType}_${testId} "fail" ${output}" >> results1/result1_${INSTRUCTION}.csv
			# fi

		
			###compare output to expected
			bool="Fail"
			if [ $output -eq $expectedValue ]; then
				bool="Pass"
			fi
			file_base_name=${t##*/}
			file_base_name=${file_base_name%.s}
			echo $file_base_name ${testType} ${bool}

			#echo "${testType}_${testId} ${bool} ${comment}" >> results1/result1.csv
			#echo ""

		done
	done


else
	i=1
	for type in r i j ; do
		TESTS="tests/${type}_type/*.s"
		touch results1/result1_${INSTRUCTION}.csv
		#>&2 echo "Instruction has been specified. Proceeding with ${INSTRUCTION} test."

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
				mipsel-linux-gnu-gcc -c tests/${type}_type/$hexed.s -o tmp1/${type}_type/$hexed.o &>/dev/null
			
				mipsel-linux-gnu-objcopy -O binary --only-section=.text tmp1/${type}_type/$hexed.o bin1/${type}_type/$hexed.bin 2>&1 >/dev/null
			
				hexdump -v bin1/${type}_type/$hexed.bin > hex1/${type}_type/$hexed.hex.txt -e '1/4 "%08x " "\n"'
				
				###compile testbench
				iverilog -g 2012 \
					mips_cpu_bus_tb_delay1.v RAM_32x2048_delay1.v ${lower_level[@]} -s mips_cpu_bus_tb_delay1 -Pmips_cpu_bus_tb_delay1.RAM_INIT_FILE=\"hex1/${type}_type/$hexed.hex.txt\" -o simulator1/mips_cpu_bus_tb_delay1_$hexed 2>/dev/null

				###run testbench
				set +e
				simulator1/mips_cpu_bus_tb_delay1_$hexed > results1/mips_cpu_bus_tb_delay1_$hexed.txt
				output=$(tail -n 1 results1/mips_cpu_bus_tb_delay1_${hexed}.txt)
				#echo "out $output"
				#echo "exp $expectedValue"
				set -e

				###testing for failure code
				# if [[ "${output}" -ne 0 ]]; then
				# 	echo "${testType}_${testId} "fail" ${output}" >> results1/result1_${INSTRUCTION}.csv
				# fi

			
				###compare output to expected
				bool="Fail"
				if [ $output -eq $expectedValue ]; then
					bool="Pass"
				fi
				file_base_name=${t##*/}
				file_base_name=${file_base_name%.s}
				echo $file_base_name ${testType} ${bool}
				#echo "${testType}_${testId} ${bool} ${comment}" >> results1/result1_${INSTRUCTION}.csv
				#echo ${bool}
				#echo ""
			fi

		done
	done

fi


