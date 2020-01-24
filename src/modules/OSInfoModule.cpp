#include "OSInfoModule.hpp"

std::string OSInfoModule::getData()
{
	std::ostringstream st;
	utsname sysinf;
	uname(&sysinf);
	st << sysinf.sysname << " | " << sysinf.nodename << " | " << sysinf.release << " | " << sysinf.version << " | "
	   << sysinf.machine << std::endl;
	return st.str();
}