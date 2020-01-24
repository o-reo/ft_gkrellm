#ifndef CPUMODULE_HPP
#define CPUMODULE_HPP

#include "AMonitorModule.hpp"
#include <utility>
#include <vector>

class CpuModule : public AMonitorModule<std::vector<int> >
{
  private:
	std::vector<std::pair<unsigned long long int, unsigned long long int> > ticks;

  protected:
  public:
	CpuModule();
	CpuModule(CpuModule const &src);
	~CpuModule();
	CpuModule &operator=(CpuModule const &src);
	virtual std::vector<int> getData();
};

#endif