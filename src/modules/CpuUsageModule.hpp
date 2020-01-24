#ifndef CPUUSAGEMODULE_HPP
#define CPUUSAGEMODULE_HPP

#include "AMonitorModule.hpp"
#include <utility>
#include <vector>

class CpuUsageModule : public AMonitorModule<std::vector<int> >
{
  private:
	std::vector<std::pair<unsigned long long int, unsigned long long int> > ticks;

  protected:
  public:
	CpuUsageModule();
	CpuUsageModule(CpuUsageModule const &src);
	~CpuUsageModule();
	CpuUsageModule &operator=(CpuUsageModule const &src);
	virtual std::vector<int> getData();
};

#endif