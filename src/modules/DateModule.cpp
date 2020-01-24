#include "DateModule.hpp"

DateModule::DateModule()
{
}

DateModule::~DateModule()
{
}

std::time_t DateModule::getData()
{
	return std::time(0);
}