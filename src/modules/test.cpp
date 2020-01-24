#include "CpuModule.hpp"
#include <chrono>
#include <iostream>
#include <thread>

int main(void)
{
	CpuModule mod;
	for (int i = 0; i < 1000; i++)
	{
		std::vector<int> load = mod.getData();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		for (int k = 0; k < load.size(); k++)
			std::cout << "core: " << k + 1 << " load: " << load[k] << " | ";
		std::cout << std::endl;
	}
}