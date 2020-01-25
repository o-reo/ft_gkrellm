#ifndef AMONITORMODULE_HPP
#define AMONITORMODULE_HPP

#include "IMonitorModule.hpp"
template <class T> class AMonitorModule : public IMonitorModule
{
  private:
	const std::string _name;

  protected:
  public:
	AMonitorModule(const std::string &name) : _name(name)
	{
	}
	AMonitorModule(AMonitorModule const &src);
	virtual ~AMonitorModule()
	{
	}
	AMonitorModule &operator=(AMonitorModule const &src);
	virtual T getData() = 0;
	virtual const std::string &getName() const
	{
		return this->_name;
	}
};

#endif