#include "CpuModule.hpp"
#include <iostream>
int main(void)
{
	CpuModule mod;
	for (int i = 0; i < 1000; i++) {
		std::vector<int> load = mod.getData();
		for (int k = 0; k < load.size(); k++)
			std::cout << "core: " << k + 1 << " load: " << load[k] << " | ";
		std::cout << std::endl;
	}
}