#ifndef CURSESDISPLAY_HPP
#define CURSESDISPLAY_HPP

#include "IMonitorDisplay.hpp"

class CursesDisplay : public IMonitorDisplay {
private:
  CursesDisplay(CursesDisplay const &src);
  CursesDisplay &operator=(CursesDisplay const &src);

protected:
public:
  CursesDisplay();
  ~CursesDisplay();
  // virtual void addWidget()
};

#endif
