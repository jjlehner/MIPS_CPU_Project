#include <iostream>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>

#include "ALU.h"

using namespace std;

/*
  6 bit input: 'ALU_operation'
  2x32 bit inputs: 'input_1' and 'input_2'
  32 bit output: 'ALU_output'
  64 bit output 'ALU_HI_LO_output'
*/

int main(int argc, char **argv, char **env){
  Verilated::commandArgs(argc, argv);
  ALU* alu_module = new ALU;

  cout << "Running ALU TestBench" << endl;

  bool hasFailed = false;
  int instr = 0;

  bitset<32> input_1;
  bitset<32> input_2;

  /////////////////////////////////
  //SLL Test
  string input1 = "00000000000000000000000010000000";
  input_1 = bitset<32>(input1);
  input_2 = bitset<32>(2);
  bitset<5> shamt(0);
  alu_module->ALU_operation = 0;

  for(int i = 6; i <= 10; i++){
    shamt.set(i-6, input_1[i]);
  }

  alu_module->input_1 = input_1.to_ulong();
  alu_module->input_2 = input_2.to_ulong();
  alu_module->eval();

  if((uint32_t)alu_module->ALU_output != (uint32_t)(input_2.to_ulong() << shamt.to_ulong())){
    cout << "SLL Testcase FAILED! - input: " <<
      (int32_t)alu_module->input_2 << "; shamt: " << shamt.to_ulong() <<
      "; Expected: " << (uint32_t)(input_2.to_ulong() << shamt.to_ulong()) << "; Got: " << (uint32_t)alu_module->ALU_output << endl;
    hasFailed = true;
  }

  //SRL Test
  alu_module->ALU_operation = 1;

  //SRA Test
  alu_module->ALU_operation = 3;

  //SLLV Test
  alu_module->ALU_operation = 4;

  //SRLV Test
  alu_module->ALU_operation = 6;

  //SRAV Test
  alu_module->ALU_operation = 7;

  //JR, JALR, MFHI, MTHI, MFLO, MTLO Test
  uint32_t jr_val1;
  uint32_t jr_val2;
  vector<int> op_codes = {8, 9, 16, 17, 18, 19};

  for(int i = 0; i < op_codes.size(); i++){
    jr_val1 = 10;
    jr_val2 = 5;
    for(int j = 0; j <= 10; j++){
      alu_module->ALU_operation = op_codes[i];
      alu_module->input_1 = jr_val1;
      alu_module->input_2 = jr_val2;
      alu_module->eval();

      if((uint32_t)alu_module->ALU_output != jr_val2){
        cout << "Testcase FAILED! Op-code: " << (uint32_t)alu_module->ALU_operation << "; Got: " << (uint32_t)alu_module->ALU_output
          << "Expected: " << jr_val2 << endl;
          hasFailed = true;
      }else{
        // cout << "Testcase Running! Op-code: " << (uint32_t)alu_module->ALU_operation << "; Got: " << (uint32_t)alu_module->ALU_output
        //   << "Expected: " << jr_val2 << endl;
        //   cout << "j = " << j << endl;
        jr_val1 += 23983;
        jr_val2 += 10410;
        continue;
      }
    }
  }

  //MULT Test - inputs: [-2147483648 : 2147483647] output: [-9223372036854775808 : 9223372036854775807]
  int32_t mult_val1;
  int32_t mult_val2;
  alu_module->ALU_operation = 24;

    //manual testcases - checking the largest bounds
  mult_val1 = -2147483648;
  mult_val2 = -2147483648;
  alu_module->input_1 = mult_val1;
  alu_module->input_2 = mult_val2;
  alu_module->eval();

  if((int64_t)alu_module->ALU_HI_LO_output != ((int64_t)mult_val1 * (int64_t)mult_val2)){
    cout << "MULT Testcase Man#1 FAILED! \n  Input1: " << (int32_t)alu_module->input_1 <<
    "; Input2: " << (int32_t)alu_module->input_1 << "; Got: " << (int64_t)alu_module->ALU_HI_LO_output <<
    "; Expected: " << ((int64_t)mult_val1 * (int64_t)mult_val2) << endl;
     hasFailed = true;
  }

  mult_val1 = -2147483648;
  mult_val2 = 2147483647;
  alu_module->input_1 = mult_val1;
  alu_module->input_2 = mult_val2;
  alu_module->eval();

  if((int64_t)alu_module->ALU_HI_LO_output != ((int64_t)mult_val1 * (int64_t)mult_val2)){
    cout << "MULT Testcase Man#2 FAILED! \n  Input1: " << (int32_t)alu_module->input_1 <<
    "; Input2: " << (int32_t)alu_module->input_1 << "; Got: " << (int64_t)alu_module->ALU_HI_LO_output <<
    "; Expected: " << ((int64_t)mult_val1 * (int64_t)mult_val2) << endl;
     hasFailed = true;
  }

  mult_val1 = 2147483647;
  mult_val2 = 2147483647;
  alu_module->input_1 = mult_val1;
  alu_module->input_2 = mult_val2;
  alu_module->eval();

  if((int64_t)alu_module->ALU_HI_LO_output != ((int64_t)mult_val1 * (int64_t)mult_val2)){
    cout << "MULT Testcase Man#3 FAILED! \n  Input1: " << (int32_t)alu_module->input_1 <<
    "; Input2: " << (int32_t)alu_module->input_1 << "; Got: " << (int64_t)alu_module->ALU_HI_LO_output <<
    "; Expected: " << ((int64_t)mult_val1 * (int64_t)mult_val2) << endl;
     hasFailed = true;
  }

    //automatic testcases
  mult_val1 = 0;
  mult_val2 = 0;

  for(int i = 0; i <= 11; i++){
    alu_module->input_1 = mult_val1;
    alu_module->input_2 = mult_val2;
    alu_module->eval();

    if((int64_t)alu_module->ALU_HI_LO_output != ((int64_t)mult_val1 * (int64_t)mult_val2)){
      cout << "MULT Testcase Auto#"<<i<<" FAILED! \n  Input1: " << (int32_t)alu_module->input_1 <<
      "; Input2: " << (int32_t)alu_module->input_1 << "; Got: " << (int64_t)alu_module->ALU_HI_LO_output <<
      "; Expected: " << ((int64_t)mult_val1 * (int64_t)mult_val2) << endl;
       hasFailed = true;
    }
    mult_val1 += 7;
    mult_val2 += -7;
  }

  //MULTU Test inputs: [0: 4294967295] output: [0 : 18446744073709551615]
  uint32_t multu_val1;
  uint32_t multu_val2;
  alu_module->ALU_operation = 25;

    //manual testcases
  multu_val1 = 4294967295;
  multu_val2 = 4294967295;
  alu_module->input_1 = multu_val1;
  alu_module->input_2 = multu_val2;
  alu_module->eval();

  if((uint64_t)alu_module->ALU_HI_LO_output != ((uint64_t)multu_val1 * (uint64_t)multu_val2)){
    cout << "MULTU Testcase Man#1 FAILED! \n  Input1: " << (uint32_t)alu_module->input_1 <<
    "; Input2: " << (uint32_t)alu_module->input_2 << "; Got: " << (uint64_t)alu_module->ALU_HI_LO_output <<
    "; Expected: " << (uint64_t)(multu_val1 * multu_val2) << endl;
    hasFailed = true;
  }

    //automatic testcases
  multu_val1 = 0;
  multu_val2 = 0;

  for(int i = 0; i <= 11; i++){
    alu_module->input_1 = multu_val1;
    alu_module->input_2 = multu_val2;
    alu_module->eval();

    if((uint64_t)alu_module->ALU_HI_LO_output != ((uint64_t)multu_val1 * (uint64_t)multu_val2)){
      cout << "MULTU Testcase Auto#"<< i <<" FAILED! \n  Input1: " << (uint32_t)alu_module->input_1 <<
      "; Input2: " << (uint32_t)alu_module->input_2 << "; Got: " << (uint64_t)alu_module->ALU_HI_LO_output <<
      "; Expected: " << (uint64_t)(multu_val1 * multu_val2) << endl;
      hasFailed = true;
    }

    multu_val1 += 860293;
    multu_val2 += 120984;
  }

  //DIV Test inputs: [-2147483648 : 2147483647]
  int32_t div_val1;
  int32_t div_val2;
  alu_module->ALU_operation = 26;

    //manual testcases - checking the largest bounds
  div_val1 = 2;
  div_val2 = 10;
  alu_module->input_1 = div_val1;
  alu_module->input_2 = div_val2;
  alu_module->eval();

  if((int64_t)alu_module->ALU_HI_LO_output != floor(((int64_t)div_val2 / (int64_t)div_val1))){
    cout << "DIV Testcase Man#1 FAILED! \n  Input1: " << (int32_t)alu_module->input_1 << "; Input2: "
    << (int32_t)alu_module->input_2 << "; Got: " << (int64_t)alu_module->ALU_HI_LO_output <<
    "; Expected: " << (div_val2/div_val1) << endl;
     hasFailed = true;
  }

  div_val1 = 1;
  div_val2 = -2147483648;
  alu_module->input_1 = div_val1;
  alu_module->input_2 = div_val2;
  alu_module->eval();

  if((int64_t)alu_module->ALU_HI_LO_output != ((int64_t)div_val2 / (int64_t)div_val1)){
    cout << "DIV Testcase Man#2 FAILED! \n  Input1: " << (int32_t)alu_module->input_1 << "; Input2: "
    << (int32_t)alu_module->input_2 << "; Got: " << (int64_t)alu_module->ALU_HI_LO_output <<
    "; Expected: " << (div_val2/div_val1) << endl;
     hasFailed = true;
  }

  div_val1 = 1;
  div_val2 = 2147483647;
  alu_module->input_1 = div_val1;
  alu_module->input_2 = div_val2;
  alu_module->eval();

  if((int64_t)alu_module->ALU_HI_LO_output != ((int64_t)div_val2 / (int64_t)div_val1)){
    cout << "DIV Testcase Man#3 FAILED! \n  Input1: " << (int32_t)alu_module->input_1 << "; Input2: "
    << (int32_t)alu_module->input_2 << "; Got: " << (int64_t)alu_module->ALU_HI_LO_output <<
    "; Expected: " << (div_val2/div_val1) << endl;
     hasFailed = true;
  }
  div_val1 = -1;
  div_val2 = 2147483647;
  alu_module->input_1 = div_val1;
  alu_module->input_2 = div_val2;
  alu_module->eval();

  if((int64_t)alu_module->ALU_HI_LO_output != ((int64_t)div_val2 / (int64_t)div_val1)){
    cout << "DIV Testcase Man#4 FAILED! \n  Input1: " << (int32_t)alu_module->input_1 << "; Input2: "
    << (int32_t)alu_module->input_2 << "; Got: " << (int64_t)alu_module->ALU_HI_LO_output <<
    "; Expected: " << (div_val2/div_val1) << endl;
     hasFailed = true;
  }

    //automatic testcases
  div_val1 = 5012031;
  div_val2 = -2147483648;

  for(int i = 0; i <= 11; i++){
    alu_module->input_1 = div_val1;
    alu_module->input_2 = div_val2;
    alu_module->eval();

    if((int64_t)alu_module->ALU_HI_LO_output != ((int64_t)div_val2 / (int64_t)div_val1)){
      cout << "DIV Testcase Auto#" << i << " FAILED! \n  Input1: " << (int32_t)alu_module->input_1 << "; Input2: "
      << (int32_t)alu_module->input_2 << "; Got: " << (int64_t)alu_module->ALU_HI_LO_output <<
      "; Expected: " << (div_val2/div_val1) << endl;
       hasFailed = true;
    }
    div_val1 += -398475;
    div_val2 += 3509348;
  }

  //DIVU Test inputs: [0: 4294967295]
  uint32_t divu_val1;
  uint32_t divu_val2;
  alu_module->ALU_operation = 27;

    //manual testing
  divu_val1 = 1;
  divu_val2 = 4294967295;
  alu_module->input_1 = divu_val1;
  alu_module->input_2 = divu_val2;
  alu_module->eval();

  if((uint64_t)alu_module->ALU_HI_LO_output != ((uint64_t)divu_val2 / (uint64_t)divu_val1)){
    cout << "DIVU Testcase Man#1 FAILED! \n  Input1: " << (uint32_t)alu_module->input_1 << "; Input2: "
    << (uint32_t)alu_module->input_2 << "; Got: " << (uint64_t)alu_module->ALU_HI_LO_output <<
    "; Expected: " << (divu_val2/divu_val1) << endl;
     hasFailed = true;
  }

    //automatic testing
  divu_val1 = 4294967295;
  divu_val2 = 4294967295;
  for(int i = 0; i <= 11; i++){
    alu_module->input_1 = divu_val1;
    alu_module->input_2 = divu_val2;
    alu_module->eval();

    if((uint64_t)alu_module->ALU_HI_LO_output != ((uint64_t)divu_val2 / (uint64_t)divu_val1)){
      cout << "DIVU Testcase Auto#"<< i <<" FAILED! \n  Input1: " << (uint32_t)alu_module->input_1 << "; Input2: "
      << (uint32_t)alu_module->input_2 << "; Got: " << (uint64_t)alu_module->ALU_HI_LO_output <<
      "; Expected: " << (divu_val2/divu_val1) << endl;
       hasFailed = true;
    }

    divu_val1 -= 350928912314;
    divu_val2 -= 8759387;
  }

  //ADD Test - [-2147483648 : 2147483647]
  int32_t add_val1;
  int32_t add_val2;
  alu_module->ALU_operation = 32;

    //manual testcases
  add_val1 = -2147483648;
  add_val2 = 2147483647;
  alu_module->input_1 = add_val1;
  alu_module->input_2 = add_val2;
  alu_module->eval();

  if((int32_t)alu_module->ALU_output != (add_val1 + add_val2)){
    cout << "ADD Testcase Man#1 FAILED! \n  Input1: " << add_val1 << "; Input2: " << add_val2 <<
    "; Got: " << (int32_t)alu_module->ALU_output << "; Expected: " <<  (add_val1 + add_val2) <<endl;
    hasFailed = true;
  }

    //automatic testcases
  add_val1 = -2147483648;
  add_val2 = 2147483647;
  for(int i = 0; i <= 11; i++){
    alu_module->input_1 = add_val1;
    alu_module->input_2 = add_val2;
    alu_module->eval();

    if((int32_t)alu_module->ALU_output != (add_val1 + add_val2)){
      cout << "ADD Testcase Auto#"<<i<<"FAILED! \n  Input1: " << add_val1 << "; Input2: " << add_val2 <<
      "; Got: " << (int32_t)alu_module->ALU_output << "; Expected: " <<  (add_val1 + add_val2) <<endl;
      hasFailed = true;
    }

    add_val1 += 298304;
    add_val2 -= 120391;
  }

  //ADDU Test - [0: 4294967295]
  uint32_t addu_val1;
  uint32_t addu_val2;
  alu_module->ALU_operation = 33;

    //manual testing
  addu_val1 = 0;
  addu_val2 = 4294967295;
  alu_module->input_1 = addu_val1;
  alu_module->input_2 = addu_val2;
  alu_module->eval();

  if((uint32_t)alu_module->ALU_output != (addu_val1 + addu_val2)){
    cout << "ADDU Testcase Man#1 FAILED! \n  Input1: " << addu_val1 << "; Input2: " << addu_val2 <<
    "; Got: " << (uint32_t)alu_module->ALU_output << "; Expected: " <<  (addu_val1 + addu_val2) <<endl;
    hasFailed = true;
  }

    //automatic testing
  addu_val1 = 0;
  addu_val2 = 0;
  for(int i = 0; i <= 11; i++){
    alu_module->input_1 = addu_val1;
    alu_module->input_2 = addu_val2;
    alu_module->eval();

    if((uint32_t)alu_module->ALU_output != (addu_val1 + addu_val2)){
      cout << "ADDU Testcase Auto#"<<i<<" FAILED! \n  Input1: " << addu_val1 << "; Input2: " << addu_val2 <<
      "; Got: " << (uint32_t)alu_module->ALU_output << "; Expected: " <<  (addu_val1 + addu_val2) <<endl;
      hasFailed = true;
    }
    addu_val1 += 43290583;
    addu_val2 += 98989119;
  }

  //SUB Test - [-2147483648 : 2147483647]
  int32_t sub_val1;
  int32_t sub_val2;
  alu_module->ALU_operation = 34;

    //manual testcases
  sub_val1 = 0;
  sub_val2 = 2147483648;
  alu_module->input_1 = sub_val1;
  alu_module->input_2 = sub_val2;
  alu_module->eval();

  if((int32_t)alu_module->ALU_output != (sub_val1 - sub_val2)){
    cout << "SUB Testcase Man#1 FAILED! \n  Input1: " << sub_val1 << "; Input2: " << sub_val2 <<
    "; Got: " << (int32_t)alu_module->ALU_output << "; Expected: " <<  (sub_val1 - sub_val2) <<endl;
    hasFailed = true;
  }

    //automatic testcases
  sub_val1 = 2147483647;
  sub_val2 = 2147483647;
  for(int i = 0; i <= 11; i++){
    alu_module->input_1 = sub_val1;
    alu_module->input_2 = sub_val2;
    alu_module->eval();

    if((int32_t)alu_module->ALU_output != (sub_val1 - sub_val2)){
      cout << "SUB Testcase Auto#"<<i<<"FAILED! \n  Input1: " << sub_val1 << "; Input2: " << sub_val2 <<
      "; Got: " << (int32_t)alu_module->ALU_output << "; Expected: " <<  (sub_val1 - sub_val2) <<endl;
      hasFailed = true;
    }
    //
    sub_val1 -= 2191830;
    sub_val2 -= 7014013;
  }

  //SUBU Test
  uint32_t subu_val1;
  uint32_t subu_val2;
  alu_module->ALU_operation = 35;

    //manual testing
  subu_val1 = 4294967295;
  subu_val2 = 0;
  alu_module->input_1 = subu_val1;
  alu_module->input_2 = subu_val2;
  alu_module->eval();

  if((uint32_t)alu_module->ALU_output != (subu_val1 - subu_val2)){
    cout << "SUBU Testcase Man#1 FAILED! \n  Input1: " << subu_val1 << "; Input2: " << subu_val2 <<
    "; Got: " << (uint32_t)alu_module->ALU_output << "; Expected: " <<  (subu_val1 - subu_val2) <<endl;
    hasFailed = true;
  }

    //automatic testing
  subu_val1 = 0;
  subu_val2 = 0;
  for(int i = 0; i <= 11; i++){
    alu_module->input_1 = subu_val1;
    alu_module->input_2 = subu_val2;
    alu_module->eval();

    if((uint32_t)alu_module->ALU_output != (subu_val1 - subu_val2)){
      cout << "SUBU Testcase Auto#"<<i<<" FAILED! \n  Input1: " << subu_val1 << "; Input2: " << subu_val2 <<
      "; Got: " << (uint32_t)alu_module->ALU_output << "; Expected: " <<  (subu_val1 - subu_val2) <<endl;
      hasFailed = true;
    }
    subu_val1 += 98989119;
    subu_val2 += 43910290;
  }
  //AND, OR, XOR, NOR Test
  string logical_input1 = "01010101010101010101010101010101";
  string logical_input2 = "01100110011001100110011001100110";
  bitset<32> logical_input_1(logical_input1);
  bitset<32> logical_input_2(logical_input2);
  bitset<32> answer;
  string answer_string;
  alu_module->input_1 = logical_input_1.to_ulong();
  alu_module->input_2 = logical_input_2.to_ulong();

    //AND
   alu_module->ALU_operation = 36;
   alu_module->eval();

   answer_string = "01000100010001000100010001000100";
   answer = bitset<32>(answer_string);

   if((uint32_t)alu_module->ALU_output != answer.to_ulong()){
     cout << "AND TestBench FAILED! \n Input1: " << bitset<32>((uint32_t)alu_module->input_1) << "; Input2: " << bitset<32>((uint32_t)alu_module->input_2)
       << "; \n  Got: " << bitset<32>((uint32_t)alu_module->ALU_output) << "; Expected: " << answer_string << endl;
      hasFailed = true;
   }

      //OR
    alu_module->ALU_operation = 37;
    alu_module->eval();

    answer_string = "01110111011101110111011101110111";
    answer = bitset<32>(answer_string);

    if((uint32_t)alu_module->ALU_output != answer.to_ulong()){
      cout << "OR TestBench FAILED! \n Input1: " << bitset<32>((uint32_t)alu_module->input_1) << "; Input2: " << bitset<32>((uint32_t)alu_module->input_2)
        << "; \n  Got: " << bitset<32>((uint32_t)alu_module->ALU_output) << "; Expected: " << answer_string << endl;
       hasFailed = true;
    }

      //XOR
    alu_module->ALU_operation = 38;
    alu_module->eval();

    answer_string = "00110011001100110011001100110011";
    answer = bitset<32>(answer_string);

    if((uint32_t)alu_module->ALU_output != answer.to_ulong()){
      cout << "XOR TestBench FAILED! \n Input1: " << bitset<32>((uint32_t)alu_module->input_1) << "; Input2: " << bitset<32>((uint32_t)alu_module->input_2)
        << "; \n  Got: " << bitset<32>((uint32_t)alu_module->ALU_output) << "; Expected: " << answer_string << endl;
        hasFailed = true;
    }

      //NOR
    alu_module->ALU_operation = 39;
    alu_module->eval();

    answer_string = "10001000100010001000100010001000";
    answer = bitset<32>(answer_string);

    if((uint32_t)alu_module->ALU_output != answer.to_ulong()){
      cout << "NOR TestBench FAILED! \n Input1: " << bitset<32>((uint32_t)alu_module->input_1) << "; Input2: " << bitset<32>((uint32_t)alu_module->input_2)
        << "; \n  Got: " << bitset<32>((uint32_t)alu_module->ALU_output) << "; Expected: " << answer_string << endl;
        hasFailed = true;
    }

  //SLT, SLTU Test

  ////////////////////////////
  if(hasFailed == true){
    cout << "ALU Testbench FAILED!" << endl;
  }else{
    cout << "ALU Testbench PASSED!" << endl;
  }
}
