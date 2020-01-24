#ifndef AMONITORMODULE_HPP
#define AMONITORMODULE_HPP

#include "IMonitorModule.hpp"
template <class T> class AMonitorModule : public IMonitorModule
{
  private:
  protected:
  public:
	AMonitorModule()
	{
	}
	AMonitorModule(AMonitorModule const &src);
	virtual ~AMonitorModule()
	{
	}
	AMonitorModule &operator=(AMonitorModule const &src);
	virtual T getData() = 0;
};

#endif