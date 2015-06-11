/******************************************************************************
*                                                                             *
* xfssiu_omron.h                                                              *
*               XFS - definitions                                             *
*               for the Sensors and Indicators - services                     *
*               Extension for ESSAF                                           *
*                                                                             *
*               Extended from XFS SIU Version 3.01 (16/11/01)                 *
*                                                                             *
******************************************************************************/
 
#ifndef __INC_XFSSIU_OMRON__H
#define __INC_XFSSIU_OMRON__H

#ifdef __cplusplus
extern "C" {
#endif

#include <xfsapi.h>
#include <xfssiu.h>

/*   be aware of alignment   */
#pragma pack(push,1)

/* SIU sensor extensions start from the end of fwSensor array */
#define     WFS_SIU_SKIMMING            (WFS_SIU_SENSORS_MAX - 0)

/* SIU Command Verbs */
//w.r.t. ticket FAE5269E1433F90A4825739A002020B5: ESSAF/XFS Specific, to control power to PC and/or devices
#define     WFS_CMD_SIU_POWER_CONTROL           (SIU_SERVICE_OFFSET + 20)


	/* Values of WFSSIUPOWERCONTROL.dwDevices */

#define     WFS_SIU_PCDEV_BILL_HANDLER          (0x0001)
#define     WFS_SIU_PCDEV_WHOLE_MACHINE         (0x8000)

/*=================================================================*/
/* SIU Execute Command Structures */
/*=================================================================*/
//w.r.t. ticket FAE5269E1433F90A4825739A002020B5: ESSAF/XFS Specific, for WFS_CMD_SIU_POWER_CONTROL
typedef struct _wfs_siu_power_control
{
    DWORD           dwDevices;
    BOOL            bPowerOn;
} WFSSIUPOWERCONTROL, * LPWFSSIUPOWERCONTROL;

/* restore alignment */
#pragma pack(pop)

#ifdef __cplusplus
}       /*extern "C"*/
#endif

#endif  /* __INC_XFSSIU_OMRON__H */
