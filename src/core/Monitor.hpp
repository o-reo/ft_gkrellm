#ifndef MONITOR_HPP
#define MONITOR_HPP

class Monitor {
private:
protected:
public:
  Monitor();
  Monitor(Monitor const &src);
  ~Monitor();
  Monitor &operator=(Monitor const &src);
  void launch();
};

#endif