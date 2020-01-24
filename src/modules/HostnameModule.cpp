/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   HostnameModule.cpp                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 19:18:42 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 22:08:59 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "HostnameModule.hpp"
#include "unistd.h"
#include <vector>

HostnameModule::HostnameModule() {}
HostnameModule::~HostnameModule() {}
std::vector<std::string> HostnameModule::getData()
{
  char hostname[_SC_HOST_NAME_MAX];
  char username[_SC_LOGIN_NAME_MAX];
  gethostname(hostname, _SC_HOST_NAME_MAX);
  getlogin_r(username, _SC_LOGIN_NAME_MAX);
  std::vector<std::string> res;
  res.push_back(hostname);
  res.push_back(username);
  return res;
}
