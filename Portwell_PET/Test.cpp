#include <iostream>
using namespace std;

#include "PET.h"

int main3() {
	PET pet;

	int rc = pet.API_Init();
	cout << "PET_API_Init = " << rc << endl;
	////////////////////////////////////////////////
	char api_version[20];
	rc = pet.API_GetVersion(api_version);
	cout << "PET_API_GetVersion = " << rc << api_version << endl;

	char bios_vendor[20];
	rc = pet.Board_GetBIOSVendor(bios_vendor);
	cout << "PET_API_GetBIOSVendor = " << rc << bios_vendor << endl;

	char bios_version[20];
	rc = pet.Board_GetBIOSVersion(bios_version);
	cout << "PET_API_GetBIOSVersion = " << rc << bios_version << endl;

	char name[20];
	rc = pet.Board_GetPlatformName(name);
	cout << "PET_Board_GetPlatformName = " << rc << name << endl;

	rc= pet.WDT_Available();
	cout << "PET_WDT_Available = " << rc << endl;

	unsigned char minimum, maximum;
	rc = pet.WDT_GetRange(0, &minimum, &maximum);
	cout << "PET_WDT_GetRange = " << rc << endl;
	printf ("The WDT second mode range: %d ~ %d (sec)\n", minimum, maximum);

	rc = pet.WDT_GetRange(1, &minimum, &maximum);
	cout << "PET_WDT_GetRange = " << rc << endl;
	printf ("The WDT minute mode range: %d ~ %d (min)\n", minimum, maximum);

	int wdt_type;
	unsigned char wdt_timeout;
	rc = pet.WDT_GetConfig(&wdt_type, &wdt_timeout);
	cout << "PET_WDT_GetConfig = " << rc << endl;
	printf ("WDT type:%d, timeout:%d\n", wdt_type, wdt_timeout);

	int cpu_num = 0;
	rc = pet.HWM_CPUNumber(&cpu_num);
	cout << "PET_HWM_CPUNumber = " << rc << endl;
	printf(" The CPU core number is %d\n", cpu_num);

	for(int i=0; i<=10; i++) {
		double cpuTemperature = 0;
		pet.HWM_CPUTemperature(i, &cpuTemperature);
		cout << "i = " << i << ", PET_HWM_CPUTemperature = " << rc << endl;
		printf ("* SYSTIN Temperature is %3.2f ('C) *\n", cpuTemperature);
	}

	double temperature = 0;
	rc = pet.HWM_SysTemperature(&temperature);
	cout << "PET_HWM_SysTemperature = " << rc << endl;
	printf ("* SYSTIN Temperature is %3.2f ('C) *\n", temperature);

	rc = pet.WDT_Trigger();
	cout << "PET_WDT_Trigger = " << rc << endl;
	rc= pet.WDT_Available();
	cout << "PET_WDT_Available = " << rc << endl;
	rc = pet.WDT_Disable();
	cout << "PET_WDT_Disable = " << rc << endl;
	rc= pet.WDT_Available();
	cout << "PET_WDT_Available = " << rc << endl;

	rc = pet.WDT_SetConfig(1, 20);
	cout << "PET_WDT_SetConfig = " << rc << endl;
	{
	int wdt_type;
	unsigned char wdt_timeout;
	rc = pet.WDT_GetConfig(&wdt_type, &wdt_timeout);
	cout << "PET_WDT_GetConfig = " << rc << endl;
	printf ("WDT type:%d, timeout:%d\n", wdt_type, wdt_timeout);
	}


	while(true) {
		rc = pet.WDT_Trigger();
		cout << "PET_WDT_Trigger = " << rc << endl;
		Sleep(60000);
	}

	rc = pet.API_Uninit();
	cout << "PET_API_Uninit = " << rc << endl;

	return 0;
}

//int main() {
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	PET pet;

	int rc = pet.API_Init();
	cout << "PET_API_Init = " << rc << endl;
	////////////////////////////////////////////////
	char api_version[128];
	rc = pet.API_GetVersion(api_version);
	cout << "PET_API_GetVersion = " << rc << " " << api_version << endl;

	char bios_vendor[128];
	rc = pet.Board_GetBIOSVendor(bios_vendor);
	cout << "PET_API_GetBIOSVendor = " << rc << " " << bios_vendor << endl;

	char bios_version[128];
	rc = pet.Board_GetBIOSVersion(bios_version);
	cout << "PET_API_GetBIOSVersion = " << rc << " " << bios_version << endl;

	char name[128];
	rc = pet.Board_GetPlatformName(name);
	cout << "PET_Board_GetPlatformName = " << rc << " " << name << endl;

	rc = pet.WDT_SetConfig(1, 5);			//5 minutes
	cout << "PET_WDT_SetConfig = " << rc << endl;

	int wdt_type;
	unsigned char wdt_timeout;
	rc = pet.WDT_GetConfig(&wdt_type, &wdt_timeout);
	cout << "PET_WDT_GetConfig = " << rc << " wdt_type = " << wdt_type << " wdt_timeout = " << static_cast<unsigned>(wdt_timeout) << endl;

	while(true) {
		rc = pet.WDT_Trigger();
		cout << "PET_WDT_Trigger = " << rc << endl;
		Sleep(60000);						//1 minute
	}

	rc = pet.API_Uninit();
	cout << "PET_API_Uninit = " << rc << endl;

	return 0;
}
