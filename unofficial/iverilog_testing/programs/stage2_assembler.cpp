#include <bits/stdc++.h>

const uint32_t ISA = 0xBFC00000; //INSTRUCTION_START_ADDRESS
int main(int argc, char *argv[]){
	for(int f = 1; f < argc; f++){
		std::map<u_int32_t, u_int32_t> memory;
		std::fstream file;
		file.open(std::string(argv[f]) + ".txt");
		std::cerr<<"Opening file "<< std::string(argv[f]) + ".txt"<<std::endl;
		assert(file.is_open());
		
		std::string line;
		for(uint32_t RAM_POS = 0;std::getline(file, line);RAM_POS+=4){
			if(line[0]=='.'){
				std::string pos = line.substr(1, pos.size() -1 );
				if(pos == "main") RAM_POS = ISA - 4; 
				else{
					RAM_POS = std::stol(pos,nullptr,16);
					RAM_POS -= 4;
					assert(RAM_POS % 4 == 0 && "RAM POSITION ON NOT WORD ALLIGNED");
				}
				continue;
			}
			std::stringstream ss(line);
			uint32_t hex;
			ss>>std::hex>>hex;
			memory[RAM_POS] = hex;
		}

		auto it = memory.begin();
		for(uint32_t pos = ISA; pos <= memory.rbegin()->first; pos += 4){
			if(pos != it->first){
				std::cout<<"0\n";
			}
			else{
				std::cout<<std::hex<<it->second<<std::endl;
				it++;
			}
		}
	}
}