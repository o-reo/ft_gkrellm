#ifndef NETMODULE_HPP
#define NETMODULE_HPP

#include "AMonitorModule.hpp"
#include <vector>

class NetModule : public AMonitorModule<std::vector<int> >
{
  private:
	NetModule &operator=(NetModule const &src);
	NetModule(NetModule const &src);

  protected:
  public:
	NetModule();
	~NetModule();
	virtual std::vector<int> getData();
};

#endif