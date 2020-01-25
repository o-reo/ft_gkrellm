#ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP

#include <string>

class IMonitorModule
{
  public:
	IMonitorModule(){};
	IMonitorModule(IMonitorModule const &src);
	virtual ~IMonitorModule(){};
	IMonitorModule &operator=(IMonitorModule const &src);
};

#endif