//============================================================================
// Name        : XFSTest.cpp
// Author      : shudong
// Version     :
// Copyright   : IBM copyright!!
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "XFSAPI.H"
#include "XFSSIU.H"
#include "XFSSIU_Omron.H"

int main(int argc, char* argv[]) {
	cout << "!!!BH2Reboot.exe!!!" << endl;
  // Display each command-line argument.
  cout << "\nCommand-line arguments:\n";
  for(int count = 0; count < argc; count++ ) {
      cout << "  argv[" << count << "]   "<< argv[count] << "\n";
  }

	DWORD dwVersionsRequired = 0x00009903;
	WFSVERSION wfsVersion;
	HRESULT rc = WFSStartUp(dwVersionsRequired, &wfsVersion);
	cout << "!!!WFSStartUp() = !!!" << rc <<endl;

    WFSVERSION srvcVersion;
    WFSVERSION spiVersion;
    HSERVICE hService;

    rc = WFSOpen((argc <= 1 ? "IOMC" : argv[1]), WFS_DEFAULT_HAPP, "SIU_REBOOT", 0, 0, 0x01019933, &srvcVersion, &spiVersion, &hService);
    cout << "!!!WFSOpen() = !!!" << rc <<endl;
    if(rc == WFS_SUCCESS) {
    	LPWFSRESULT lpResult;
		WFSSIUPOWERCONTROL powerOff;
		powerOff.dwDevices = WFS_SIU_PCDEV_BILL_HANDLER;
		powerOff.bPowerOn = false;
    	rc = WFSExecute(hService, WFS_CMD_SIU_POWER_CONTROL, &powerOff, WFS_INDEFINITE_WAIT, &lpResult);
    	cout << "!!!WFS_CMD_SIU_POWER_CONTROL = !!!" << rc << " RequestID = " << lpResult->RequestID << endl;
    	if(lpResult != NULL) {
    		cout << "!!!WFSFreeResult() = !!!" << WFSFreeResult(lpResult) <<endl;
    	}
    	if(rc == WFS_SUCCESS) {
    		Sleep(5000);	//sleep 5 seconds
    		LPWFSRESULT lpResult2;
			WFSSIUPOWERCONTROL powerOn;
			powerOn.dwDevices = WFS_SIU_PCDEV_BILL_HANDLER;
			powerOn.bPowerOn = true;
			rc = WFSExecute(hService, WFS_CMD_SIU_POWER_CONTROL, &powerOn, WFS_INDEFINITE_WAIT, &lpResult2);
			cout << "!!!WFS_CMD_SIU_POWER_CONTROL = !!!" << rc << " RequestID = " << lpResult->RequestID << endl;
	    	if(lpResult2 != NULL) {
	    		cout << "!!!WFSFreeResult() = !!!" << WFSFreeResult(lpResult2) <<endl;
	    	}
	    	Sleep(5000);	//sleep 5 seconds
    	}
    	rc = WFSClose(hService);
    	cout << "!!!WFSClose() = !!!" << rc <<endl;
    }
	rc = WFSCleanUp();
	cout << "!!!WFSCleanUp() = !!!" << rc <<endl;
	return 0;
}
