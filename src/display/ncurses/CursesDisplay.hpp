#ifndef CURSESDISPLAY_HPP
#define CURSESDISPLAY_HPP

#include "IMonitorDisplay.hpp"

#include "AWidget.hpp"
#include "Config.hpp"

class CursesDisplay : public IMonitorDisplay {
private:
  CursesDisplay(CursesDisplay const &src);
  CursesDisplay &operator=(CursesDisplay const &src);

protected:
public:
  CursesDisplay();
  ~CursesDisplay();
  void render(void);
  AWidget *addWidget(Config::WIDGET_TYPE type);
  // virtual void addWidget()
};

#endif
