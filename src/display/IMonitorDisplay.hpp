#ifndef IMONITORDISPLAY_HPP
#define IMONITORDISPLAY_HPP

#include "IMonitorModule.hpp"
#include "AWidget.hpp"
#include "coords.h"
#include "Config.hpp"

class IMonitorDisplay
{
  private:
	IMonitorDisplay &operator=(IMonitorDisplay const &src);
	IMonitorDisplay(IMonitorDisplay const &src);

  protected:
  public:
	IMonitorDisplay()
	{
	}
	virtual ~IMonitorDisplay()
	{
	}
	virtual AWidget *addWidget(Config::WIDGET_TYPE) = 0;
	virtual void render() = 0;
};

#endif