#ifndef OSINFOMODULE_HPP
#define OSINFOMODULE_HPP

#include "AMonitorModule.hpp"
#include <string>
#include <sys/utsname.h>

class OSInfoModule : public AMonitorModule<std::vector<std::pair<std::string, std::string> > >
{
  private:
	OSInfoModule &operator=(OSInfoModule const &src);
	OSInfoModule(OSInfoModule const &src);

  protected:
  public:
	OSInfoModule();
	~OSInfoModule();
	virtual std::vector<std::pair<std::string, std::string> > getData();
};

#endif
