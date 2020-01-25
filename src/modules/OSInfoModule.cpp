#include "OSInfoModule.hpp"
#include <vector>
#include <sys/sysctl.h>
#include <sstream>

OSInfoModule::OSInfoModule() : AMonitorModule("OS Details")
{
}

OSInfoModule::~OSInfoModule()
{
}

std::vector<std::pair<std::string, std::string> > OSInfoModule::getData()
{
	utsname sysinf;
	uname(&sysinf);
	std::vector<std::pair<std::string, std::string> > res;

	char buffer[1024];
	size_t size = sizeof(buffer);
	if (sysctlbyname("hw.model", &buffer, &size, 0, 0) < 0)
		throw std::runtime_error("Could not reach system information");

	res.push_back(std::make_pair<std::string, std::string>("Model", buffer));
	res.push_back(std::make_pair<std::string, std::string>("OS", sysinf.sysname));
	res.push_back(std::make_pair<std::string, std::string>("Release", sysinf.release));

	std::istringstream sbuf(sysinf.version);
	std::string part;
	std::getline(sbuf, part, ':');
	res.push_back(std::make_pair<std::string, std::string>("Version", part));
	res.push_back(std::make_pair<std::string, std::string>("Family", sysinf.machine));
	return res;
}