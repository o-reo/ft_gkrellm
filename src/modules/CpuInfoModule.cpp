#include "CpuInfoModule.hpp"
#include <sys/sysctl.h>

CpuInfoModule::CpuInfoModule()
{
}

CpuInfoModule::~CpuInfoModule()
{
}

std::vector<std::string> CpuInfoModule::getData()
{
	std::vector<std::string> stvec;
	char buffer[1024];
	size_t size = sizeof(buffer);
	if (sysctlbyname("machdep.cpu.brand_string", &buffer, &size, 0, 0) < 0)
		throw std::runtime_error("Could not reach cpu information");
	stvec.push_back(buffer);
	if (sysctlbyname("hw.physicalcpu", &buffer, &size, 0, 0) < 0)
		throw std::runtime_error("Could not reach cpu information");
	stvec.push_back(std::to_string(*(reinterpret_cast<int *>(buffer))));
	return stvec;
}
