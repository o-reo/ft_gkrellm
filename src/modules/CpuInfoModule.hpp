#ifndef CPUINFOMODULE_HPP
#define CPUINFOMODULE_HPP

#include "AMonitorModule.hpp"
#include <string>

class CpuInfoModule : public AMonitorModule<std::string>
{
  private:
	CpuInfoModule &operator=(CpuInfoModule const &src);
	CpuInfoModule(CpuInfoModule const &src);

  protected:
  public:
	CpuInfoModule();
	~CpuInfoModule();
	virtual std::string getData();
};

#endif