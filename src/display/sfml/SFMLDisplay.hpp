#ifndef SFMLDISPLAY_HPP
#define SFMLDISPLAY_HPP

#include "IMonitorDisplay.hpp"
#include "HostnameModule.hpp"
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