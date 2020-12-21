#ifndef PARSE_HPP
#define PARSE_HPP

#include <fstream>
#include <vector>
#include <string>
#include <cstdint>

////simulation

vector<uint32_t> reading (istream &src);

int32_t simulator(uint32_t *memory);

bool setTarget(const string &s);

uint32_t decode_inst_opcode(const string &s);

bool 
