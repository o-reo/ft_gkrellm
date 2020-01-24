#include "RamModule.hpp"
#include <iostream>
#include <mach/host_info.h>
#include <mach/mach_host.h>
#include <mach/task.h>
#include <mach/task_info.h>
#include <sstream>
#include <sys/sysctl.h>

RamModule::RamModule()
{
}

RamModule::~RamModule()
{
}

std::vector<int> RamModule::getData()
{
	std::vector<int> meminfo;
	double unit = 1024 * 1024;

	// Total Memory
	char buffer[1024];
	size_t b_size = sizeof(buffer);
	if (sysctlbyname("hw.memsize", &buffer, &b_size, 0, 0) < 0)
		throw std::runtime_error("Could not reach cpu information");
	std::istringstream tot_info(buffer);
	int memsize;
	tot_info >> memsize;
	meminfo.push_back(*reinterpret_cast<long *>(buffer) / unit);

	// Used memory
	int mib[6];
	mib[0] = CTL_HW;
	mib[1] = HW_PAGESIZE;

	int pagesize;
	size_t length;
	length = sizeof(pagesize);
	if (sysctl(mib, 2, &pagesize, &length, NULL, 0) < 0)
		throw std::runtime_error("Error getting system page size");

	mach_msg_type_number_t count = HOST_VM_INFO_COUNT;

	vm_statistics_data_t vmstat;
	if (host_statistics(mach_host_self(), HOST_VM_INFO, (host_info_t)&vmstat, &count) != KERN_SUCCESS)
		throw std::runtime_error("Error getting system statistics");

	double total = vmstat.wire_count + vmstat.active_count + vmstat.inactive_count + vmstat.free_count;
	double wired = vmstat.wire_count / total;
	double active = vmstat.active_count / total;
	double inactive = vmstat.inactive_count / total;
	double free = vmstat.free_count;

	task_basic_info_64_data_t info;
	unsigned size = sizeof(info);
	task_info(mach_task_self(), TASK_BASIC_INFO_64, (task_info_t)&info, &size);
	meminfo.push_back(total * pagesize / unit);
	return meminfo;
}
