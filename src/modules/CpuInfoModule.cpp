#include "CpuInfoModule.hpp"
#include <sys/sysctl.h>
#include <sstream>

CpuInfoModule::CpuInfoModule() : AMonitorModule("CPU Details")
{
}

CpuInfoModule::~CpuInfoModule()
{
}

std::vector<std::pair<std::string, std::string> > CpuInfoModule::getData()
{
	std::vector<std::pair<std::string, std::string> > stvec;
	char buffer[1024];
	size_t size = sizeof(buffer);
	if (sysctlbyname("machdep.cpu.brand_string", &buffer, &size, 0, 0) < 0)
		throw std::runtime_error("Could not reach cpu information");
	std::istringstream sbuf(buffer);
	std::string part;
	std::getline(sbuf, part, '@');
	stvec.push_back(std::make_pair<std::string, std::string>("Model", part));
	std::getline(sbuf, part, '@');
	stvec.push_back(std::make_pair<std::string, std::string>("Freq", part));
	if (sysctlbyname("hw.physicalcpu", &buffer, &size, 0, 0) < 0)
		throw std::runtime_error("Could not reach cpu information");
	stvec.push_back(
		std::make_pair<std::string, std::string>("Cores", std::to_string(*(reinterpret_cast<int *>(buffer)))));
	return stvec;
}
