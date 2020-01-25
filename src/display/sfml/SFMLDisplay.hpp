#ifndef SFMLDISPLAY_HPP
#define SFMLDISPLAY_HPP

#include "CpuInfoModule.hpp"
#include "CpuUsageModule.hpp"
#include "DateModule.hpp"
#include "HostnameModule.hpp"
#include "IMonitorDisplay.hpp"
#include "OSInfoModule.hpp"
#include "RamModule.hpp"
#include "widgets/SFMLWidgetClock.tpp"
#include "widgets/SFMLWidgetGauge.tpp"
#include "widgets/SFMLWidgetText.tpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class SFMLDisplay : public IMonitorDisplay
{
  private:
	sf::RenderWindow _window;

  protected:
  public:
	SFMLDisplay();
	SFMLDisplay(SFMLDisplay const &src);
	~SFMLDisplay();
	SFMLDisplay &operator=(SFMLDisplay const &src);
	// virtual void addWidget();
	void render();
};

#endif