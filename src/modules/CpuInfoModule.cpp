#include "CpuInfoModule.hpp"
#include <sstream>
#include <sys/sysctl.h>

CpuInfoModule::CpuInfoModule()
{
}

CpuInfoModule::~CpuInfoModule()
{
}

std::string CpuInfoModule::getData()
{
	std::ostringstream data;
	char buffer[1024];
	size_t size = sizeof(buffer);
	if (sysctlbyname("machdep.cpu.brand_string", &buffer, &size, 0, 0) < 0)
		throw std::runtime_error("Could not reach cpu information");
	data << "model: " << buffer << " | ";
	if (sysctlbyname("hw.physicalcpu", &buffer, &size, 0, 0) < 0)
		throw std::runtime_error("Could not reach cpu information");
	data << "core: " << *(reinterpret_cast<int*>(buffer)) << std::endl;
	return data.str();
}
