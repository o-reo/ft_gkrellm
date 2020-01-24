#include "CpuModule.hpp"
#include <fstream>
#include <iostream>
#include <mach/mach_host.h>
#include <mach/mach_host.h>
#include <unistd.h>
CpuModule::CpuModule() : ticks()
{
	unsigned int cpu_count;
	processor_cpu_load_info_t cpu_load;
	mach_msg_type_number_t cpu_msg_count;
	host_processor_info(mach_host_self(), PROCESSOR_CPU_LOAD_INFO, &cpu_count,
						reinterpret_cast<processor_info_array_t *>(&cpu_load), &cpu_msg_count);
	for (unsigned int i = 0; i < cpu_count; ++i)
		this->ticks.push_back(std::make_pair<unsigned long long int, unsigned long long int>(0, 0));
}
// CpuModule::CpuModule(CpuModule const &src)
// {
// }
CpuModule::~CpuModule()
{
}
// CpuModule &CpuModule::operator=(CpuModule const &src)
// {
// }

std::vector<int> CpuModule::getData()
{
	unsigned int cpu_count;
	processor_cpu_load_info_t cpu_load;
	mach_msg_type_number_t cpu_msg_count;
	host_processor_info(mach_host_self(), PROCESSOR_CPU_LOAD_INFO, &cpu_count,
						reinterpret_cast<processor_info_array_t *>(&cpu_load), &cpu_msg_count);
	std::vector<int> load(4);
	for (unsigned int i = 0; i < cpu_count; ++i)
	{
		unsigned long long int used = cpu_load[i].cpu_ticks[CPU_STATE_USER];
		used += cpu_load[i].cpu_ticks[CPU_STATE_NICE];
		used += cpu_load[i].cpu_ticks[CPU_STATE_SYSTEM];
		unsigned long long int total = used + cpu_load[i].cpu_ticks[CPU_STATE_IDLE];

		load[i] = (100 * float(used - this->ticks[i].first) / float(total - this->ticks[i].second));
		std::cout << used - this->ticks[i].first << std::endl;
		std::cout << total << std::endl;
		this->ticks[i] = std::make_pair<unsigned long long int, unsigned long long int>(used, total);
	}
	return load;
}