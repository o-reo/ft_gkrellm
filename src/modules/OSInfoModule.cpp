#include "OSInfoModule.hpp"
#include <vector>

std::vector<std::string> OSInfoModule::getData()
{
	utsname sysinf;
	uname(&sysinf);
	std::vector<std::string> res;

	res.push_back(sysinf.sysname);
	res.push_back(sysinf.nodename);
	res.push_back(sysinf.release);
	res.push_back(sysinf.version);
	res.push_back(sysinf.machine);
	return res;
}