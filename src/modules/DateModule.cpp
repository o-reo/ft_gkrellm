#include "DateModule.hpp"

DateModule::DateModule() : AMonitorModule("Time")
{
}

DateModule::~DateModule()
{
}

std::time_t DateModule::getData()
{
	return std::time(0);
}