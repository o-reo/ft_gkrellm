#ifndef SFMLDISPLAY_HPP
#define SFMLDISPLAY_HPP

#include "IMonitorDisplay.hpp"

class SFMLDisplay : public IMonitorDisplay {
private:
protected:
public:
  SFMLDisplay();
  SFMLDisplay(SFMLDisplay const &src);
  ~SFMLDisplay();
  SFMLDisplay &operator=(SFMLDisplay const &src);
  // virtual void addWidget();
};

#endif