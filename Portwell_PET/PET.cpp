#include "PET_Type.h"
#include "PET.h"

#include <iostream>
using namespace std;

PET::PET() {
	handle = LoadLibrary(PET_LIBRARY_FILE);
	if(handle != NULL) {
		PET_API_Init 				= (DLL_PET_API_Init)GetProcAddress(handle, "PET_API_Init");
		PET_API_Uninit				= (DLL_PET_API_Uninit)GetProcAddress(handle, "PET_API_Uninit");
		PET_API_GetVersion			= (DLL_PET_API_GetVersion)GetProcAddress(handle, "PET_API_GetVersion");
		PET_Board_GetBIOSVendor		= (DLL_PET_Board_GetBIOSVendor)GetProcAddress(handle, "PET_Board_GetBIOSVendor");
		PET_Board_GetBIOSVersion	= (DLL_PET_Board_GetBIOSVersion)GetProcAddress(handle, "PET_Board_GetBIOSVersion");
		PET_Board_GetPlatformName	= (DLL_PET_Board_GetPlatformName)GetProcAddress(handle, "PET_Board_GetPlatformName");

		PET_WDT_Available			= (DLL_PET_WDT_Available)GetProcAddress(handle, "PET_WDT_Available");
		PET_WDT_GetRange			= (DLL_PET_WDT_GetRange)GetProcAddress(handle, "PET_WDT_GetRange");
		PET_WDT_SetConfig			= (DLL_PET_WDT_SetConfig)GetProcAddress(handle, "PET_WDT_SetConfig");
		PET_WDT_GetConfig			= (DLL_PET_WDT_GetConfig)GetProcAddress(handle, "PET_WDT_GetConfig");
		PET_WDT_Trigger				= (DLL_PET_WDT_Trigger)GetProcAddress(handle, "PET_WDT_Trigger");
		PET_WDT_Disable				= (DLL_PET_WDT_Disable)GetProcAddress(handle, "PET_WDT_Disable");

		PET_HWM_CPUNumber			= (DLL_PET_HWM_CPUNumber)GetProcAddress(handle, "PET_HWM_CPUNumber");
		PET_HWM_CPUTemperature		= (DLL_PET_HWM_CPUTemperature)GetProcAddress(handle, "PET_HWM_CPUTemperature");
		PET_HWM_SysTemperature		= (DLL_PET_HWM_SysTemperature)GetProcAddress(handle, "PET_HWM_SysTemperature");
	}
}

PET::~PET() {
	if(handle != NULL) {
		FreeLibrary(handle);
	}
	handle = NULL;
}

int PET::API_Init() {
	if(handle == NULL) {
		return DLL_NOT_LOADED;
	}
	if(PET_API_Init == NULL) {
		return DLL_FUNCTION_NOT_LOADED;
	}
	return PET_API_Init();
}

int PET::API_Uninit() {
	if(handle == NULL) {
		return DLL_NOT_LOADED;
	}
	if(PET_API_Uninit != NULL) {
		return DLL_FUNCTION_NOT_LOADED;
	}
	return PET_API_Uninit();
}

int PET::API_GetVersion(char* api_version) {
	if(handle == NULL) {
		return DLL_NOT_LOADED;
	}
	if(PET_API_GetVersion == NULL) {
		return DLL_FUNCTION_NOT_LOADED;
	}
	return PET_API_GetVersion(api_version);
}

int PET::Board_GetBIOSVendor(char* bios_vendor) {
	if(handle == NULL) {
		return DLL_NOT_LOADED;
	}
	if(PET_Board_GetBIOSVendor == NULL) {
		return DLL_FUNCTION_NOT_LOADED;
	}
	return PET_Board_GetBIOSVendor(bios_vendor);
}

int PET::Board_GetBIOSVersion(char* bios_version) {
	if(handle == NULL) {
		return DLL_NOT_LOADED;
	}
	if(PET_Board_GetBIOSVersion == NULL) {
		return DLL_FUNCTION_NOT_LOADED;
	}
	return PET_Board_GetBIOSVersion(bios_version);
}

int PET::Board_GetPlatformName(char* name) {
	if(handle == NULL) {
		return DLL_NOT_LOADED;
	}
	if(PET_Board_GetPlatformName == NULL) {
		return DLL_FUNCTION_NOT_LOADED;
	}
	return PET_Board_GetPlatformName(name);
}

int PET::WDT_Available() {
	if(handle == NULL) {
		return DLL_NOT_LOADED;
	}
	if(PET_WDT_Available == NULL) {
		return DLL_FUNCTION_NOT_LOADED;
	}
	return PET_WDT_Available();
}

int PET::WDT_GetRange(int type, unsigned char* minimum, unsigned char* maximum) {
	if(handle == NULL) {
		return DLL_NOT_LOADED;
	}
	if(PET_WDT_GetRange == NULL) {
		return DLL_FUNCTION_NOT_LOADED;
	}
	return PET_WDT_GetRange(type, minimum, maximum);
}

int PET::WDT_SetConfig(int type, unsigned char timeout) {
	if(handle == NULL) {
		return DLL_NOT_LOADED;
	}
	if(PET_WDT_SetConfig == NULL) {
		return DLL_FUNCTION_NOT_LOADED;
	}
	return PET_WDT_SetConfig(type, timeout);
}

int PET::WDT_GetConfig(int* type, unsigned char* timeout) {
	if(handle == NULL) {
		return DLL_NOT_LOADED;
	}
	if(PET_WDT_GetConfig == NULL) {
		return DLL_FUNCTION_NOT_LOADED;
	}
	return PET_WDT_GetConfig(type, timeout);
}

int PET::WDT_Trigger() {
	if(handle == NULL) {
		return DLL_NOT_LOADED;
	}
	if(PET_WDT_Trigger == NULL) {
		return DLL_FUNCTION_NOT_LOADED;
	}
	return PET_WDT_Trigger();
}

int PET::WDT_Disable() {
	if(handle == NULL) {
		return DLL_NOT_LOADED;
	}
	if(PET_WDT_Disable == NULL) {
		return DLL_FUNCTION_NOT_LOADED;
	}
	return PET_WDT_Disable();
}

int PET::HWM_CPUNumber(int* cpu_num) {
	if(handle == NULL) {
		return DLL_NOT_LOADED;
	}
	if(PET_HWM_CPUNumber == NULL) {
		return DLL_FUNCTION_NOT_LOADED;
	}
	return PET_HWM_CPUNumber(cpu_num);
}

int PET::HWM_CPUTemperature(int cpu_num, double* cputemp_value) {
	if(handle == NULL) {
		return DLL_NOT_LOADED;
	}
	if(PET_HWM_CPUTemperature == NULL) {
		return DLL_FUNCTION_NOT_LOADED;
	}
	return PET_HWM_CPUTemperature(cpu_num, cputemp_value);
}

int PET::HWM_SysTemperature(double* systemp_value) {
	if(handle == NULL) {
		return DLL_NOT_LOADED;
	}
	if(PET_HWM_SysTemperature == NULL) {
		return DLL_FUNCTION_NOT_LOADED;
	}
	return PET_HWM_SysTemperature(systemp_value);
}
