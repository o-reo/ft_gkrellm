#ifndef OSINFOMODULE_HPP
#define OSINFOMODULE_HPP

#include "AMonitorModule.hpp"
#include <sys/utsname.h>
#include <string>
#include <sstream>

class OSInfoModule : public AMonitorModule<std::string>
{
  private:
	OSInfoModule(OSInfoModule const &src);
	OSInfoModule &operator=(OSInfoModule const &src);

  protected:
  public:
	OSInfoModule(){}
	~OSInfoModule(){}
	virtual std::string getData();
};

#endif
