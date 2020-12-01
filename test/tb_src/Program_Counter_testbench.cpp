#include <iostream>

#include "Program_Counter.h"

using namespace std;

/*
  Testbench to test "Program_Counter.v" and the "Program_Counter" module
    32 bit input: 'address_input'
    'clk' and active low 'enable'
    32 bit output: 'address_output'
  Output should become Input on positive clock edges unless the 'enable' signal
  is high
    'enable' = 0 -> input becomes output
             = 1 -> output remains constant
*/

int main(int argc, char **argv, char **env){
  Verilated::commandArgs(argc, argv);
  Program_Counter* pc_module = new Program_Counter;

  uint32_t input = 0;
  uint32_t output;

  pc_module->clk = 0;
  pc_module->enable = 0;
  pc_module->address_input = input;

  //testing that the increment works
  for(int i = 0; i < 10; i++){
    uint32_t old_input = pc_module->address_output;
    input += 4;
    pc_module->address_input = input;
    pc_module->eval();

    pc_module->clk = 1;
    pc_module->eval();
    pc_module->clk = 0;
    pc_module->eval();

    if(pc_module->address_output != old_input + 4){
      cout << "Program Counter TestBench FAILED! Expected: " << old_input + 4 <<  " Got: " <<  pc_module->address_output << " pc_enable: " << (bool)pc_module->enable << endl;
      return 1;
    }
  }

  pc_module->enable = 1;
  pc_module->eval();

  //testing that the enable line works
  for(int i = 0; i < 10; i++){
    uint32_t old_input = pc_module->address_output;
    input += 4;
    pc_module->address_input = input;
    pc_module->eval();

    pc_module->clk = 1;
    pc_module->eval();
    pc_module->clk = 0;
    pc_module->eval();

    if(pc_module->address_output != old_input){
      cout << "Program Counter TestBench FAILED! Expected: " << old_input <<  " Got: " <<  pc_module->address_output << " pc_enable: " << (bool)pc_module->enable << endl;
      return 1;
    }
  }

  cout << "Program Counter TestBench PASSED!" << endl;
  pc_module->final();
  delete pc_module;
  return 0;
}
