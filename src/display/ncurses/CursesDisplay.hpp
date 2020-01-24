#ifndef CURSESDISPLAY_HPP
#define CURSESDISPLAY_HPP

#include "IMonitorDisplay.hpp"

class CursesDisplay : public IMonitorDisplay {
private:
protected:
public:
  CursesDisplay();
  // CursesDisplay(CursesDisplay const &src);
  ~CursesDisplay();
  // CursesDisplay &operator=(CursesDisplay const &src);
  // virtual void addWidget()
};

#endif