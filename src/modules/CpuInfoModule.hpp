#ifndef CPUINFOMODULE_HPP
#define CPUINFOMODULE_HPP

#include "AMonitorModule.hpp"
#include <string>
#include <utility>
#include <vector>

class CpuInfoModule : public AMonitorModule<std::vector<std::pair<std::string, std::string> > >
{
  private:
	CpuInfoModule &operator=(CpuInfoModule const &src);
	CpuInfoModule(CpuInfoModule const &src);

  protected:
  public:
	CpuInfoModule();
	~CpuInfoModule();
	virtual std::vector<std::pair<std::string, std::string> > getData();
};

#endif