#include "OSInfoModule.hpp"
#include <vector>

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

	res.push_back(std::make_pair<std::string, std::string>("System", sysinf.sysname));
	res.push_back(std::make_pair<std::string, std::string>("Node", sysinf.nodename));
	res.push_back(std::make_pair<std::string, std::string>("Release", sysinf.release));
	res.push_back(std::make_pair<std::string, std::string>("Version", sysinf.version));
	res.push_back(std::make_pair<std::string, std::string>("Machine", sysinf.machine));
	return res;
}