#ifndef RAMMODULE_HPP
#define RAMMODULE_HPP

#include "AMonitorModule.hpp"
#include <vector>

class RamModule : public AMonitorModule<std::vector<int> >
{
  private:
	RamModule &operator=(RamModule const &src);
	RamModule(RamModule const &src);

  protected:
  public:
	RamModule();
	~RamModule();
	virtual std::vector<int> getData();
};

#endif