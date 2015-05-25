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


#include <iostream>
using namespace std;

int main2() {
	HMODULE g_hModule = LoadLibrary("PET.dll");
	if(g_hModule != NULL) {
		DLL_PET_API_Init m_funcPET_API_Init	= (DLL_PET_API_Init)GetProcAddress(g_hModule, "PET_API_Init");
		DLL_PET_API_Uninit m_funcPET_API_Uninit	= (DLL_PET_API_Uninit)GetProcAddress(g_hModule, "PET_API_Uninit");
		DLL_PET_API_GetVersion m_funcPET_API_GetVersion	= (DLL_PET_API_GetVersion)GetProcAddress(g_hModule, "PET_API_GetVersion");
		DLL_PET_Board_GetBIOSVendor m_funcPET_Board_GetBIOSVendor	= (DLL_PET_Board_GetBIOSVendor)GetProcAddress(g_hModule, "PET_Board_GetBIOSVendor");
		DLL_PET_Board_GetBIOSVersion m_funcPET_Board_GetBIOSVersion	= (DLL_PET_Board_GetBIOSVersion)GetProcAddress(g_hModule, "PET_Board_GetBIOSVersion");
		DLL_PET_Board_GetPlatformName m_funcPET_Board_GetPlatformName	= (DLL_PET_Board_GetPlatformName)GetProcAddress(g_hModule, "PET_Board_GetPlatformName");

		DLL_PET_WDT_Available m_funcPET_WDT_Available	= (DLL_PET_WDT_Available)GetProcAddress(g_hModule, "PET_WDT_Available");
		DLL_PET_WDT_GetRange m_funcPET_WDT_GetRange	= (DLL_PET_WDT_GetRange)GetProcAddress(g_hModule, "PET_WDT_GetRange");
		DLL_PET_WDT_SetConfig m_funcPET_WDT_SetConfig	= (DLL_PET_WDT_SetConfig)GetProcAddress(g_hModule, "PET_WDT_SetConfig");
		DLL_PET_WDT_GetConfig m_funcPET_WDT_GetConfig	= (DLL_PET_WDT_GetConfig)GetProcAddress(g_hModule, "PET_WDT_GetConfig");
		DLL_PET_WDT_Trigger m_funcPET_WDT_Trigger	= (DLL_PET_WDT_Trigger)GetProcAddress(g_hModule, "PET_WDT_Trigger");
		DLL_PET_WDT_Disable m_funcPET_WDT_Disable	= (DLL_PET_WDT_Disable)GetProcAddress(g_hModule, "PET_WDT_Disable");

		DLL_PET_HWM_CPUNumber m_funcPET_HWM_CPUNumber	= (DLL_PET_HWM_CPUNumber)GetProcAddress(g_hModule, "PET_HWM_CPUNumber");
		DLL_PET_HWM_CPUTemperature m_funcPET_HWM_CPUTemperature	= (DLL_PET_HWM_CPUTemperature)GetProcAddress(g_hModule, "PET_HWM_CPUTemperature");
		DLL_PET_HWM_SysTemperature m_funcPET_HWM_SysTemperature	= (DLL_PET_HWM_SysTemperature)GetProcAddress(g_hModule, "PET_HWM_SysTemperature");

		int rc = m_funcPET_API_Init();
		cout << "PET_API_Init = " << rc << endl;
		////////////////////////////////////////////////
		char api_version[20];
		rc = m_funcPET_API_GetVersion(api_version);
		cout << "PET_API_GetVersion = " << rc << api_version << endl;

		char bios_vendor[20];
		rc = m_funcPET_Board_GetBIOSVendor(bios_vendor);
		cout << "PET_API_GetBIOSVendor = " << rc << bios_vendor << endl;

		char bios_version[20];
		rc = m_funcPET_Board_GetBIOSVersion(bios_version);
		cout << "PET_API_GetBIOSVersion = " << rc << bios_version << endl;

		char name[20];
		rc = m_funcPET_Board_GetPlatformName(name);
		cout << "PET_Board_GetPlatformName = " << rc << name << endl;

		rc= m_funcPET_WDT_Available();
		cout << "PET_WDT_Available = " << rc << endl;

		unsigned char minimum, maximum;
		rc = m_funcPET_WDT_GetRange(0, &minimum, &maximum);
		cout << "PET_WDT_GetRange = " << rc << endl;
		printf ("The WDT second mode range: %d ~ %d (sec)\n", minimum, maximum);

		rc = m_funcPET_WDT_GetRange(1, &minimum, &maximum);
		cout << "PET_WDT_GetRange = " << rc << endl;
		printf ("The WDT minute mode range: %d ~ %d (min)\n", minimum, maximum);

		int wdt_type;
		unsigned char wdt_timeout;
		rc = m_funcPET_WDT_GetConfig(&wdt_type, &wdt_timeout);
		cout << "PET_WDT_GetConfig = " << rc << endl;
		printf ("WDT type:%d, timeout:%d\n", wdt_type, wdt_timeout);

		int cpu_num = 0;
		rc = m_funcPET_HWM_CPUNumber(&cpu_num);
		cout << "PET_HWM_CPUNumber = " << rc << endl;
		printf(" The CPU core number is %d\n", cpu_num);

		for(int i=0; i<=10; i++) {
			double cpuTemperature = 0;
			m_funcPET_HWM_CPUTemperature(i, &cpuTemperature);
			cout << "i = " << i << ", PET_HWM_CPUTemperature = " << rc << endl;
			printf ("* SYSTIN Temperature is %3.2f ('C) *\n", cpuTemperature);
		}

		double temperature = 0;
		rc = m_funcPET_HWM_SysTemperature(&temperature);
		cout << "PET_HWM_SysTemperature = " << rc << endl;
		printf ("* SYSTIN Temperature is %3.2f ('C) *\n", temperature);

		rc = m_funcPET_WDT_Trigger();
		cout << "PET_WDT_Trigger = " << rc << endl;
		rc= m_funcPET_WDT_Available();
		cout << "PET_WDT_Available = " << rc << endl;
		rc = m_funcPET_WDT_Disable();
		cout << "PET_WDT_Disable = " << rc << endl;
		rc= m_funcPET_WDT_Available();
		cout << "PET_WDT_Available = " << rc << endl;

		rc = m_funcPET_WDT_SetConfig(1, 20);
		cout << "PET_WDT_SetConfig = " << rc << endl;
		{
		int wdt_type;
		unsigned char wdt_timeout;
		rc = m_funcPET_WDT_GetConfig(&wdt_type, &wdt_timeout);
		cout << "PET_WDT_GetConfig = " << rc << endl;
		printf ("WDT type:%d, timeout:%d\n", wdt_type, wdt_timeout);
		}


		while(true) {
			rc = m_funcPET_WDT_Trigger();
			cout << "PET_WDT_Trigger = " << rc << endl;
			Sleep(60000);
		}

		rc = m_funcPET_API_Uninit();
		cout << "PET_API_Uninit = " << rc << endl;
	}
	if (g_hModule != NULL) {
		FreeLibrary(g_hModule);
	}
	return 0;
}
