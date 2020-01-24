#ifndef DATEMODULE_HPP
#define DATEMODULE_HPP

#include "AMonitorModule.hpp"
#include <ctime>
#include <vector>

class DateModule : public AMonitorModule<std::vector<std::time_t> >
{
  private:
  protected:
  public:
	DateModule();
	DateModule(DateModule const &src);
	~DateModule();
	DateModule &operator=(DateModule const &src);
	virtual std::vector<std::time_t> getData();
};

#endif