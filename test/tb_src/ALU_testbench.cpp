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
bool hasFailed = false;

ALU* setInputsAndEval(ALU* alu, uint32_t operation, int32_t input1, int32_t input2){
  alu->ALU_operation = operation;
  alu->input_1 = input1;
  alu->input_2 = input2;
  alu->eval();
  return alu;
}

ALU* setUInputsAndEval(ALU* alu, uint32_t operation, uint32_t input1, uint32_t input2){
  alu->ALU_operation = operation;
  alu->input_1 = input1;
  alu->input_2 = input2;
  alu->eval();
  return alu;
}

void sllCheck(ALU* alu, uint32_t input1, uint32_t input2){
  bitset<5> shamt(input1);
  bitset<32> input_1(0);

  for(int i = 6; i < 11; i++){
    input_1.set(i, shamt[i-6]);
  }

  alu = setUInputsAndEval(alu, 0, input_1.to_ulong(), input2);

  if((uint32_t)alu->ALU_output != (uint32_t)(input2 << shamt.to_ulong())){
    cout << "SLL Testcase FAILED! \n  input: " <<
      (int32_t)alu->input_2 << "; shamt: " << shamt.to_ulong() <<
      "; Expected: " << (uint32_t)(input2 << shamt.to_ulong()) << "; Got: " << (uint32_t)alu->ALU_output << endl;
    cout << " input: " << bitset<32>(input2) << endl;
    cout << " Got: " << bitset<32>((uint32_t)alu->ALU_output).to_string() << "; Expected: " << bitset<32>((uint32_t)(input2 << shamt.to_ulong())).to_string() << endl;
    hasFailed = true;
  }
}

void srlCheck(ALU* alu, uint32_t input1, uint32_t input2){
  bitset<5> shamt(input1);
  bitset<32> input_1(0);

  for(int i = 6; i < 11; i++){
    input_1.set(i, shamt[i-6]);
  }

  alu = setUInputsAndEval(alu, 1, input_1.to_ulong(), input2);

  if((uint32_t)alu->ALU_output != (uint32_t)(input2 >> shamt.to_ulong())){
    cout << "SRL Testcase FAILED! \n  input: " <<
      (int32_t)alu->input_2 << "; shamt: " << shamt.to_ulong() <<
      "; Expected: " << (uint32_t)(input2 >> shamt.to_ulong()) << "; Got: " << (uint32_t)alu->ALU_output << endl;
    cout << " input: " << bitset<32>(input2) << endl;
    cout << " Got: " << bitset<32>((uint32_t)alu->ALU_output).to_string() << "; Expected: " << bitset<32>((uint32_t)(input2 >> shamt.to_ulong())).to_string() << endl;
    hasFailed = true;
  }
}

void sraCheck(ALU* alu, int32_t input1, int32_t input2){
  bitset<5> shamt(input1);
  bitset<32> input_1(0);

  for(int i = 6; i < 11; i++){
    input_1.set(i, shamt[i-6]);
  }

  alu = setInputsAndEval(alu, 3, (int32_t)input_1.to_ulong(), input2);

  if((int32_t)alu->ALU_output != (int32_t)(input2 >> shamt.to_ulong())){
    cout << "SRA Testcase FAILED! \n  input: " <<
      input2 << "; shamt: " << shamt.to_ulong() <<
      "; Expected: " << (int32_t)(input2 >> shamt.to_ulong()) << "; Got: " << (int32_t)alu->ALU_output << endl;
    cout << " input: " << bitset<32>(input2) << endl;
    cout << " Got: " << bitset<32>((int32_t)alu->ALU_output).to_string() << "; Expected: " << bitset<32>((int32_t)(input2 >> shamt.to_ulong())).to_string() << endl;
    hasFailed = true;
  }
}

void sllvCheck(ALU* alu, uint32_t input1, uint32_t input2){
  bitset<5> shamt(input1);
  bitset<32> input_1(0);

  for(int i = 0; i < 5; i++){
    input_1.set(i, shamt[i]);
  }

  alu = setInputsAndEval(alu, 4, input_1.to_ulong(), input2);
  if((uint32_t)alu->ALU_output != (uint32_t)(input2 << shamt.to_ulong())){
    cout << "SLLV Testcase FAILED! \n  input: " <<
      (int32_t)alu->input_2 << "; shamt: " << shamt.to_ulong() <<
      "; Expected: " << (uint32_t)(input2 << shamt.to_ulong()) << "; Got: " << (uint32_t)alu->ALU_output << endl;
    cout << " input: " << bitset<32>(input2) << endl;
    cout << " Got: " << bitset<32>((uint32_t)alu->ALU_output).to_string() << "; Expected: " << bitset<32>((uint32_t)(input2 << shamt.to_ulong())).to_string() << endl;
    hasFailed = true;
  }
}

void srlvCheck(ALU* alu, uint32_t input1, uint32_t input2){
  bitset<5> shamt(input1);
  bitset<32> input_1(0);

  for(int i = 0; i < 5; i++){
    input_1.set(i, shamt[i]);
  }

  alu = setInputsAndEval(alu, 6, input_1.to_ulong(), input2);
  if((uint32_t)alu->ALU_output != (uint32_t)(input2 >> shamt.to_ulong())){
    cout << "SRLV Testcase FAILED! \n  input: " <<
      (int32_t)alu->input_2 << "; shamt: " << shamt.to_ulong() <<
      "; Expected: " << (uint32_t)(input2 >> shamt.to_ulong()) << "; Got: " << (uint32_t)alu->ALU_output << endl;
    cout << " input: " << bitset<32>(input2) << endl;
    cout << " Got: " << bitset<32>((uint32_t)alu->ALU_output).to_string() << "; Expected: " << bitset<32>((uint32_t)(input2 >> shamt.to_ulong())).to_string() << endl;
    hasFailed = true;
  }
}

void sravCheck(ALU* alu, int32_t input1, int32_t input2){
  bitset<5> shamt(input1);
  bitset<32> input_1(0);

  for(int i = 0; i < 5; i++){
    input_1.set(i, shamt[i]);
  }

  alu = setInputsAndEval(alu, 7, (int32_t)input_1.to_ulong(), input2);

  if((int32_t)alu->ALU_output != (int32_t)(input2 >> shamt.to_ulong())){
    cout << "SRAV Testcase FAILED! \n  input: " <<
      input2 << "; shamt: " << shamt.to_ulong() <<
      "; Expected: " << (int32_t)(input2 >> shamt.to_ulong()) << "; Got: " << (int32_t)alu->ALU_output << endl;
    cout << " input: " << bitset<32>(input2) << endl;
    cout << " Got: " << bitset<32>((int32_t)alu->ALU_output).to_string() << "; Expected: " << bitset<32>((int32_t)(input2 >> shamt.to_ulong())).to_string() << endl;
    hasFailed = true;
  }
}

void jrCheck(ALU* alu, uint32_t input1, uint32_t input2){
  //also tests JALR, MFHI, MTHI, MFLO, MTLO
  vector<int> op_codes = {8, 9, 16, 17, 18, 19};

  for(int i = 0; i < op_codes.size(); i++){
    for(int j = 0; j <= 10; j++){
      alu->ALU_operation = op_codes[i];
      alu = setUInputsAndEval(alu, op_codes[i], input1, input2);

      if((uint32_t)alu->ALU_output != input2){
        cout << "Testcase FAILED! Op-code: " << (uint32_t)alu->ALU_operation << "; Got: " << (uint32_t)alu->ALU_output
          << "; Expected: " << input2 << endl;
          hasFailed = true;
      }
      input1 += 23983;
      input2 += 10410;
    }
  }
}

void multCheck(ALU* alu, int32_t input1, int32_t input2){
  alu = setInputsAndEval(alu, 24, input1, input2);

  bitset<64> mult_ans(0);
  bitset<32> mult_ans_hi;
  bitset<32> mult_ans_lo;

  mult_ans_lo = bitset<32>((int32_t)alu->ALU_LO_output);
  mult_ans_hi = bitset<32>((int32_t)alu->ALU_HI_output);

  for(int i = 0; i < 64; i++){
    if(i<=31){
      mult_ans[i] = mult_ans_lo[i];
    }else{
      mult_ans[i] = mult_ans_hi[i-32];
    }
  }

  if((int64_t)mult_ans.to_ulong() != ((int64_t)input1 * (int64_t)input2)){
    cout << "MULT Testcase FAILED! \n  Input1: " << (int32_t)alu->input_1 <<
    "; Input2: " << (int32_t)alu->input_2 << "; Got: " << (int64_t)mult_ans.to_ulong() <<
    "; Expected: " << ((int64_t)input1 * (int64_t)input2) << endl;
    cout << bitset<32>(alu->ALU_HI_output).to_string() << " " << bitset<32>(alu->ALU_LO_output).to_string() << endl;
    cout << bitset<32>(alu->ALU_HI_output).to_string() << bitset<32>(alu->ALU_LO_output).to_string() << endl;
    cout << mult_ans.to_string() << endl;
    hasFailed = true;
  }
}

void multuCheck(ALU* alu, uint32_t input1, uint32_t input2){
  alu = setUInputsAndEval(alu, 25, input1, input2);

  bitset<64> multu_ans(0);
  bitset<32> multu_ans_hi;
  bitset<32> multu_ans_lo;

  multu_ans_lo = bitset<32>((uint32_t)alu->ALU_LO_output);
  multu_ans_hi = bitset<32>((uint32_t)alu->ALU_HI_output);

  for(int i = 0; i < 64; i++){
    if(i<=31){
      multu_ans[i] = multu_ans_lo[i];
    }else{
      multu_ans[i] = multu_ans_hi[i-32];
    }
  }

  if((uint64_t)multu_ans.to_ulong() != ((uint64_t)input1 * (uint64_t)input2)){
    cout << "MULTU Testcase FAILED! \n  Input1: " << (uint32_t)alu->input_1 <<
    "; Input2: " << (uint32_t)alu->input_2 << "; Got: " << (uint64_t)multu_ans.to_ulong() <<
    "; Expected: " << ((uint64_t)input1 * (uint64_t)input2) << endl;
    cout << bitset<32>(alu->ALU_HI_output).to_string() << " " << bitset<32>(alu->ALU_LO_output).to_string() << endl;
    cout << bitset<32>(alu->ALU_HI_output).to_string() << bitset<32>(alu->ALU_LO_output).to_string() << endl;
    cout << multu_ans.to_string() << endl;
    hasFailed = true;
  }
}

void divCheck(ALU* alu, int32_t input1, int32_t input2){
  alu = setInputsAndEval(alu, 26, input1, input2);

  bitset<64> div_ans(0);
  bitset<32> div_ans_hi;
  bitset<32> div_ans_lo;

  div_ans_lo = bitset<32>((int32_t)alu->ALU_LO_output);
  div_ans_hi = bitset<32>((int32_t)alu->ALU_HI_output);

  for(int i = 0; i < 64; i++){
    if(i<=31){
      div_ans[i] = div_ans_lo[i];
    }else{
      div_ans[i] = div_ans_hi[i-32];
    }
  }

  if((int64_t)div_ans.to_ulong() != ((int64_t)input2 / (int64_t)input1)){
    cout << "DIV Testcase FAILED! \n  Input1: " << (int32_t)alu->input_1 <<
    "; Input2: " << (int32_t)alu->input_2 << "; Got: " << (int64_t)div_ans.to_ulong() <<
    "; Expected: " << ((int64_t)input2 / (int64_t)input1) << endl;
    cout << bitset<32>(alu->ALU_HI_output).to_string() << " " << bitset<32>(alu->ALU_LO_output).to_string() << " - HI LO" << endl;
    cout << bitset<32>(alu->ALU_HI_output).to_string() << bitset<32>(alu->ALU_LO_output).to_string() << " - HI_LO_OUTPUT" << endl;
    cout << div_ans.to_string() << " - DIV_ANS" << endl;
    hasFailed = true;
  }
}

void divuCheck(ALU* alu, uint32_t input1, uint32_t input2){
  alu = setUInputsAndEval(alu, 27, input1, input2);

  bitset<64> divu_ans(0);
  bitset<32> divu_ans_hi;
  bitset<32> divu_ans_lo;

  divu_ans_lo = bitset<32>((uint32_t)alu->ALU_LO_output);
  divu_ans_hi = bitset<32>((uint32_t)alu->ALU_HI_output);

  for(int i = 0; i < 64; i++){
    if(i<=31){
      divu_ans[i] = divu_ans_lo[i];
    }else{
      divu_ans[i] = divu_ans_hi[i-32];
    }
  }

  if((uint64_t)divu_ans.to_ulong() != ((uint64_t)input2 / (uint64_t)input1)){
    cout << "DIVU Testcase FAILED! \n  Input1: " << (uint32_t)alu->input_1 <<
    "; Input2: " << (uint32_t)alu->input_2 << "; Got: " << (uint64_t)divu_ans.to_ulong() <<
    "; Expected: " << ((uint64_t)input2 / (uint64_t)input1) << endl;
    cout << bitset<32>(alu->ALU_HI_output).to_string() << " " << bitset<32>(alu->ALU_LO_output).to_string() << " - HI LO" << endl;
    cout << bitset<32>(alu->ALU_HI_output).to_string() << bitset<32>(alu->ALU_LO_output).to_string() << " - HI_LO_OUTPUT" << endl;
    cout << divu_ans.to_string() << " - DIVU_ANS" << endl;
    hasFailed = true;
  }
}

void addCheck(ALU* alu, int32_t input1, int32_t input2){
  alu = setInputsAndEval(alu, 32, input1, input2);

  if((int32_t)alu->ALU_output != (input1 + input2)){
    cout << "ADD Testcase FAILED! \n  Input1: " << alu->input_1 << "; Input2: " << alu->input_2 <<
    "; Got: " << (int32_t)alu->ALU_output << "; Expected: " <<  (input1 + input2) <<endl;
    hasFailed = true;
  }
}

void adduCheck(ALU* alu, uint32_t input1, uint32_t input2){
  alu = setUInputsAndEval(alu, 33, input1, input2);

  if((uint32_t)alu->ALU_output != (input1 + input2)){
    cout << "ADDU Testcase FAILED! \n  Input1: " << alu->input_1 << "; Input2: " << alu->input_2 <<
    "; Got: " << (uint32_t)alu->ALU_output << "; Expected: " <<  (input1 + input2) <<endl;
    hasFailed = true;
  }
}

void subCheck(ALU* alu, int32_t input1, uint32_t input2){
  alu = setInputsAndEval(alu, 34, input1, input2);

  if((uint32_t)alu->ALU_output != (input1 - input2)){
    cout << "SUB Testcase FAILED! \n  Input1: " << alu->input_1 << "; Input2: " << alu->input_2 <<
    "; Got: " << (uint32_t)alu->ALU_output << "; Expected: " <<  (input1 - input2) <<endl;
    hasFailed = true;
  }
}

void subuCheck(ALU* alu, uint32_t input1, uint32_t input2){
  alu = setUInputsAndEval(alu, 35, input1, input2);

  if((uint32_t)alu->ALU_output != (input1 - input2)){
    cout << "SUBU Testcase FAILED! \n  Input1: " << alu->input_1 << "; Input2: " << alu->input_2 <<
    "; Got: " << (uint32_t)alu->ALU_output << "; Expected: " <<  (input1 - input2) <<endl;
    hasFailed = true;
  }
}

void bitwiseCheck(ALU* alu, string input1, string input2){
  bitset<32> input_1(input1);
  bitset<32> input_2(input2);
  bitset<32> answer;

  //AND
  alu = setUInputsAndEval(alu, 36, input_1.to_ulong(), input_2.to_ulong());
  answer = (input_1 & input_2);
  if((uint32_t)alu->ALU_output != answer.to_ulong()){
    cout << "AND TestBench FAILED! \n Input1: " << bitset<32>((uint32_t)alu->input_1) << "; Input2: " << bitset<32>((uint32_t)alu->input_2)
      << "; \n  Got: " << bitset<32>((uint32_t)alu->ALU_output) << "; Expected: " << answer.to_string() << endl;
     hasFailed = true;
  }

  //OR
  alu = setUInputsAndEval(alu, 37, input_1.to_ulong(), input_2.to_ulong());
  answer = (input_1 | input_2);
  if((uint32_t)alu->ALU_output != answer.to_ulong()){
    cout << "OR TestBench FAILED! \n Input1: " << bitset<32>((uint32_t)alu->input_1) << "; Input2: " << bitset<32>((uint32_t)alu->input_2)
      << "; \n  Got: " << bitset<32>((uint32_t)alu->ALU_output) << "; Expected: " << answer.to_string() << endl;
     hasFailed = true;
  }

  //XOR
  alu = setUInputsAndEval(alu, 38, input_1.to_ulong(), input_2.to_ulong());
  answer = (input_1 ^ input_2);
  if((uint32_t)alu->ALU_output != answer.to_ulong()){
    cout << "XOR TestBench FAILED! \n Input1: " << bitset<32>((uint32_t)alu->input_1) << "; Input2: " << bitset<32>((uint32_t)alu->input_2)
      << "; \n  Got: " << bitset<32>((uint32_t)alu->ALU_output) << "; Expected: " << answer.to_string() << endl;
     hasFailed = true;
  }

  //NOR
  alu = setUInputsAndEval(alu, 39, input_1.to_ulong(), input_2.to_ulong());
  answer = ~(input_1 | input_2);
  if((uint32_t)alu->ALU_output != answer.to_ulong()){
    cout << "NOR TestBench FAILED! \n Input1: " << bitset<32>((uint32_t)alu->input_1) << "; Input2: " << bitset<32>((uint32_t)alu->input_2)
      << "; \n  Got: " << bitset<32>((uint32_t)alu->ALU_output) << "; Expected: " << answer.to_string() << endl;
     hasFailed = true;
  }
}

void sltCheck(ALU* alu, int32_t input1, int32_t input2){
  alu = setInputsAndEval(alu, 42, input1, input2);

  if(input1 < input2){
    if((uint32_t)alu->ALU_output != bitset<32>(1).to_ulong()){
      cout << "SLT TestBench FAILED! \n Input1: " << input1 << "; Input2: " << input2 << "; Got: "
        << bitset<32>((uint32_t)alu->ALU_output) << "; Exptected: " << bitset<32>(1).to_string() << endl;
    }
  }else{
    if((uint32_t)alu->ALU_output != 0){
      cout << "SLT TestBench FAILED! \n Input1: " << input1 << "; Input2: " << input2 << "; Got: "
        << bitset<32>((uint32_t)alu->ALU_output) << "; Exptected: " << 0 << endl;
    }
  }
}

void sltuCheck(ALU* alu, uint32_t input1, uint32_t input2){
  alu = setInputsAndEval(alu, 43, input1, input2);

  if(input1 < input2){
    if((uint32_t)alu->ALU_output != 1){
      cout << "SLT TestBench FAILED! \n Input1: " << input1 << "; Input2: " << input2 << "; Got: "
        << bitset<32>((uint32_t)alu->ALU_output) << "; Exptected: " << 1 << endl;
    }
  }else{
    if((uint32_t)alu->ALU_output != 0){
      cout << "SLT TestBench FAILED! \n Input1: " << input1 << "; Input2: " << input2 << "; Got: "
        << bitset<32>((uint32_t)alu->ALU_output) << "; Exptected: " << 0 << endl;
    }
  }
}

////////////////////// MAIN ///////////////////////////////////////////

int main(int argc, char **argv, char **env){
  Verilated::commandArgs(argc, argv);
  ALU* alu_module = new ALU;
  cout << "Running ALU TestBench" << endl;

  /////////////////////////////////
  //SLL Test
  sllCheck(alu_module, 3, 6);
  sllCheck(alu_module, 20, 2);

  //SRL Test
  srlCheck(alu_module, 1, 179);
  srlCheck(alu_module, 4, 500);

  //SRA Test
  sraCheck(alu_module, 1, -77);
  sraCheck(alu_module, 2, 50);
  sraCheck(alu_module, 2, -100);

  //SLLV Test
  sllvCheck(alu_module, 5, 10);
  sllvCheck(alu_module, 4, 17);
  sllvCheck(alu_module, 9, 28);

  //SRLV Test
  srlvCheck(alu_module, 5, 200);
  srlvCheck(alu_module, 8, 654);
  srlvCheck(alu_module, 12, 12741);

  //SRAV Test
  sravCheck(alu_module, 5, -200);
  sravCheck(alu_module, 12, 800);

  //JR, JALR, MFHI, MTHI, MFLO, MTLO Test
  jrCheck(alu_module, 5, 10);

  //MULT Test - inputs: [-2147483648 : 2147483647] output: [-9223372036854775808 : 9223372036854775807]
    //manual testcases - checking the largest bounds
  multCheck(alu_module, -2147483648, -2147483648);
  multCheck(alu_module, -2147483648, 2147483647);
  multCheck(alu_module, 2147483647, 2147483647);

    //automatic testcases
  for(int i = 0; i <= 11; i++){
    multCheck(alu_module, (i+120398), (i+646));
  }

  //MULTU Test inputs: [0: 4294967295] output: [0 : 18446744073709551615]
    //manual testcases
  multuCheck(alu_module, 4294967295, 4294967295);

    //automatic testcases
  for(int i = 0; i <= 11; i++){
    multuCheck(alu_module, 0+2094358*i, 0+34650*i);
  }

  //DIV Test inputs: [-2147483648 : 2147483647]
    //manual testcases - checking the largest bounds
  divCheck(alu_module, 2, 10);
  divCheck(alu_module, 1, -2147483648);
  divCheck(alu_module, 1, 2147483647);
  divCheck(alu_module, -1, 2147483647);

    //automatic testcases
  for(int i = 0; i <= 11; i++){
    divCheck(alu_module, 1-(12913*i), 1+(38502*i));
  }

  //DIVU Test inputs: [0: 4294967295]
    //manual testing
  divuCheck(alu_module, 1, 4294967295);

    //automatic testing
  for(int i = 0; i <= 11; i++){
    divuCheck(alu_module, 4294967295-23645644298*i, 4294967295-67815*i);
  }

  //ADD Test - [-2147483648 : 2147483647]
    //manual testcases
  addCheck(alu_module, -2147483648, 2147483647);

    //automatic testcases
  for(int i = 0; i <= 11; i++){
    addCheck(alu_module, 0-238497*i, 0+123124*i);
  }

  //ADDU Test - [0: 4294967295]
    //manual testing
  adduCheck(alu_module, 0, 4294967295);

    //automatic testing

  for(int i = 0; i <= 11; i++){
    adduCheck(alu_module, 0+i*1234098, 0+i*20384028);
  }

  //SUB Test - [-2147483648 : 2147483647]
    //manual testcases
  subCheck(alu_module, 0, 2147483648);

    //automatic testcases
  for(int i = 0; i <= 11; i++){
    subCheck(alu_module, 2147483647-2191830*i, 2147483647-7014013*i);
  }

  //SUBU Test
    //manual testing
  subuCheck(alu_module, 4294967295, 0);

    //automatic testing
  for(int i = 0; i <= 11; i++){
    subuCheck(alu_module, i+98989119, i+43910290);
  }

  //AND, OR, XOR, NOR Test
  bitwiseCheck(alu_module, "01010101010101010101010101010101", "01100110011001100110011001100110");

  //SLT, SLTU Test
  sltCheck(alu_module, 5, 10);
  sltCheck(alu_module, -10, 5);

  sltuCheck(alu_module, 20, 30);
  sltuCheck(alu_module, 30, 20);

  ////////////////////////////
  if(hasFailed == true){
    cout << "ALU Testbench FAILED!" << endl;
  }else{
    cout << "ALU Testbench PASSED!" << endl;
  }
}
