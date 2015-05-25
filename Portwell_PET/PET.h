/*
 * PETAPI.h
 *
 *  Created on: Sep 23, 2014
 *      Author: shudong
 */

#ifndef PETAPI_H_
#define PETAPI_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <windows.h>

typedef int (WINAPI* DLL_PET_API_Init)();
typedef int (WINAPI* DLL_PET_API_Uninit)();
typedef int (WINAPI* DLL_PET_API_GetVersion)(char*);
typedef int (WINAPI* DLL_PET_Board_GetBIOSVendor)(char*);
typedef int (WINAPI* DLL_PET_Board_GetBIOSVersion)(char*);
typedef int (WINAPI* DLL_PET_Board_GetPlatformName)(char*);

typedef int (WINAPI* DLL_PET_WDT_Available)();
typedef int (WINAPI* DLL_PET_WDT_GetRange)(int, unsigned char*, unsigned char*);
typedef int (WINAPI* DLL_PET_WDT_SetConfig)(int, unsigned char);
typedef int (WINAPI* DLL_PET_WDT_GetConfig)(int*, unsigned char*);
typedef int (WINAPI* DLL_PET_WDT_Trigger)();
typedef int (WINAPI* DLL_PET_WDT_Disable)();

typedef int (WINAPI* DLL_PET_HWM_CPUNumber)(int*);
typedef int (WINAPI* DLL_PET_HWM_CPUTemperature)(int, double*);
typedef int (WINAPI* DLL_PET_HWM_SysTemperature)(double*);

#ifdef __cplusplus
}       /*extern "C"*/
#endif

#define PET_LIBRARY_FILE			"PET.dll"
#define	DLL_NOT_LOADED				-1
#define	DLL_FUNCTION_NOT_LOADED		-2

class PET {
protected:
	// Handle to a DLL
	HMODULE handle;

private:
	// Function pointers
	DLL_PET_API_Init				PET_API_Init;
	DLL_PET_API_Uninit				PET_API_Uninit;
	DLL_PET_API_GetVersion			PET_API_GetVersion;
	DLL_PET_Board_GetBIOSVendor		PET_Board_GetBIOSVendor;
	DLL_PET_Board_GetBIOSVersion	PET_Board_GetBIOSVersion;
	DLL_PET_Board_GetPlatformName	PET_Board_GetPlatformName;

	DLL_PET_WDT_Available			PET_WDT_Available;
	DLL_PET_WDT_GetRange			PET_WDT_GetRange;
	DLL_PET_WDT_SetConfig			PET_WDT_SetConfig;
	DLL_PET_WDT_GetConfig			PET_WDT_GetConfig;
	DLL_PET_WDT_Trigger				PET_WDT_Trigger;
	DLL_PET_WDT_Disable				PET_WDT_Disable;

	DLL_PET_HWM_CPUNumber			PET_HWM_CPUNumber;
	DLL_PET_HWM_CPUTemperature		PET_HWM_CPUTemperature;
	DLL_PET_HWM_SysTemperature		PET_HWM_SysTemperature;

public:
	// Constructor and Destructor
	PET();
	~PET();

	// Public API Functions.
	int API_Init();
	int API_Uninit();
	int API_GetVersion(char* api_version);
	int Board_GetBIOSVendor(char* bios_vendor);
	int Board_GetBIOSVersion(char* bios_version);
	int Board_GetPlatformName(char* name);

	int WDT_Available();
	int WDT_GetRange(int type, unsigned char* minimum, unsigned char* maximum);
	int WDT_SetConfig(int type, unsigned char timeout);
	int WDT_GetConfig(int* type, unsigned char* timeout);
	int WDT_Trigger();
	int WDT_Disable();

	int HWM_CPUNumber(int* cpu_num);
	int HWM_CPUTemperature(int cpu_num, double* cputemp_value);
	int HWM_SysTemperature(double* systemp_value);
};

#endif /* PETAPI_H_ */
