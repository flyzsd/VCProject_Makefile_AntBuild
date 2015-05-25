#ifndef	__PORTWELL_USETYPE__
#define	__PORTWELL_USETYPE__


// Return value definition
#define		NOERROR	                        0
#define		UNKNOWN_ERROR	                1
#define		DRIVER_NOT_FOUND	            2
#define		DRIVER_NOT_LOADED	            3
#define		DRIVER_NOT_LOADED_ON_NETWORK	4
#define		NOSUPPORTED_PLATFORM	        5
#define		INITIAL_ERROR					6
#define		INVALID_PARAMETER				7
#define		READ_ERROR						8
#define		WRITE_ERROR						9
#define		NOT_SUPPORT						10
#define		UNAVAILAVLE_SLEEP_TIME			11
#define		CANNOT_SET_IO_PERMISSION	    12
#define		CANNOT_SET_BACK_IO_PERMISSION	13
#define		NOT_READY						14
#define		UNAVAILABLE_SOUND				15
#define		DMI_GETMISS						16


//API releated value
//Voltage read value define
typedef enum 
{
    VOL_VCORE, 
	VOL_VCCDDR,
	VOL_3P3V,
	VOL_VCC,
	VOL_12V,
	VOL_24V,
	VOL_VBAT
} VOLTAGE_TYPE;

//Fan value define
typedef enum  
{
    CPUFAN,
    SYSFAN,
    AUXFAN
} FANTYPE;

typedef enum
{
	SECOND_MODE = 0,
	MINUTE_MODE
} WDT_TYPE;

typedef enum
{
	GPIO_OUTPUT,
	GPIO_INPUT,
} GPIO_TYPE;

typedef enum
{
	GPIO_LOW,
	GPIO_HIGH
} GPIO_RW;

typedef enum
{
    SM_WRITE,
    SM_READ,
} SMBUS_TYPE;

typedef struct 
{
    int tjMax;
	int maxFrequency;
	char vendorName[13];
	int steppingId;
	int familyId;
	int modeId;
	int typeId;

	char CacheL1[150];
	char CacheL2[150];
	char CacheL3[150];

	char cacheTlbInfo[15][150];
	int cacheTlbInfoLength;
	char features[64][150];
	int featuresLength;

	double (*getVoltage)();
	int (*getCurrentFrequency)();
    int (*getCpuTemperature)();

}CpuInfo;

#endif