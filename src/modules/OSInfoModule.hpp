#ifndef OSINFOMODULE_HPP
#define OSINFOMODULE_HPP

#include "AMonitorModule.hpp"
#include <sys/utsname.h>
#include <string>
#include <sstream>

class OSInfoModule : public AMonitorModule<std::string>
{
  private:
  protected:
  public:
	OSInfoModule();
	OSInfoModule(OSInfoModule const &src);
	~OSInfoModule();
	OSInfoModule &operator=(OSInfoModule const &src);
	virtual std::string getData();
};

#endif