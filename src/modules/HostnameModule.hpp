#ifndef HOSTNAMEMODULE_HPP
#define HOSTNAMEMODULE_HPP
#include "AMonitorModule.hpp"
#include <string>
#include <utility>

class HostnameModule : public AMonitorModule<std::vector<std::pair<std::string, std::string> > >
{
  private:
  protected:
  public:
	HostnameModule();
	HostnameModule(HostnameModule const &src);
	~HostnameModule();
	HostnameModule &operator=(HostnameModule const &src);
	virtual std::vector<std::pair<std::string, std::string> > getData();
};
#endif
