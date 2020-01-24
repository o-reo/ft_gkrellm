#ifndef HOSTNAMEMODULE_HPP
#define HOSTNAMEMODULE_HPP
#include "AMonitorModule.hpp"
#include "Logger.hpp"
#include <string>

class HostnameModule : public AMonitorModule<std::string>
{
  private:
  protected:
  public:
	HostnameModule();
	HostnameModule(HostnameModule const &src);
	~HostnameModule();
	HostnameModule &operator=(HostnameModule const &src);
	virtual std::string getData();
};

#endif