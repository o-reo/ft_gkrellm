#include "HostnameModule.hpp"
#include "unistd.h"
#include <sstream>

HostnameModule::HostnameModule() {}

HostnameModule::~HostnameModule() {}

std::string HostnameModule::getData() {
  char hostname[_SC_HOST_NAME_MAX];
  char username[_SC_LOGIN_NAME_MAX];
  gethostname(hostname, _SC_HOST_NAME_MAX);
  getlogin_r(username, _SC_LOGIN_NAME_MAX);
  std::ostringstream st;
  st << hostname << " - " << username << std::endl;
  return st.str();
}