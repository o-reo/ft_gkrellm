#ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP

class IMonitorModule {
public:
  IMonitorModule(){};
  IMonitorModule(IMonitorModule const &src);
  virtual ~IMonitorModule(){};
  IMonitorModule &operator=(IMonitorModule const &src);
};

#endif