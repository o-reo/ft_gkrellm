#ifndef CPUUSAGEMODULE_HPP
#define CPUUSAGEMODULE_HPP

#include "AMonitorModule.hpp"
#include <utility>
#include <vector>

class CpuUsageModule : public AMonitorModule<std::vector<int> >
{
  private:
	std::vector<std::vector<int> > _avg;
	std::vector<std::pair<unsigned long long int, unsigned long long int> > ticks;

	CpuUsageModule &operator=(CpuUsageModule const &src);
	CpuUsageModule(CpuUsageModule const &src);

  protected:
  public:
	CpuUsageModule();
	~CpuUsageModule();
	virtual std::vector<int> getData();
};

#endif