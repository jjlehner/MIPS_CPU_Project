#include <bits/stdc++.h>

int main(){
	std::string line;
	while(std::getline(std::cin, line)){
		for(int c = 0; c + 1< line.size(); c+=2){
			std::swap(line[c], line[c+1]);
		}
		std::reverse(line.begin(), line.end());
		std::cout<<line<<std::endl;
	}
}