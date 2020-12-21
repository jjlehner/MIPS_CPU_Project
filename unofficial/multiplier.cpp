#include <bits/stdc++.h>

uint64_t a = 0xFFFF0000;
uint64_t b = 2;

int main(){
	std::bitset<64> bin(a*b);
	std::cout<<bin<<std::endl;
}
