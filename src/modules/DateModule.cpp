#include "DateModule.hpp"

DateModule::DateModule()
{
}
// DateModule::DateModule(DateModule const &src)
// {
// }
DateModule::~DateModule()
{
}
// DateModule &DateModule::operator=(DateModule const &src)
// {
// }

std::time_t DateModule::getData()
{
	return std::time(0);
}