//This example has been sourced and edited from 
// http://libk8055.sourceforge.net/

#include <cstdlib>
#include <windows.h>
#include <iostream>

typedef void(CALLBACK* t_func )(int         );
typedef void(CALLBACK* t_func0)(            );
typedef int (CALLBACK* t_func1)(            );
typedef void(CALLBACK* t_func2)(int *, int *);
typedef void(CALLBACK* t_func3)(int  , int  );
typedef int (CALLBACK* t_func4)(int         );
typedef bool(CALLBACK* t_func5)(int         );

								// general use
t_func4 OpenDevice;				// int  OpenDevice            (int CardAddress       );
t_func0 CloseDevice;			// void CloseDevice           (                      );
t_func0 Version_;				// void Version               (                      );
t_func1 SearchDevices;			// int  SearchDevices         (                      );
t_func4 SetCurrentDevice;		// int  SetCurrentDevice      (int CardAddress       );
								// ADC
t_func4 ReadAnalogChannel;		// int  ReadAnalogChannel     (int Channel           );
t_func2 ReadAllAnalog;			// void ReadAllAnalog         (int *Data1 ,int *Data2);
								// DAC
t_func3 OutputAnalogChannel;	// void OutputAnalogChannel   (int Channel, int Data );
t_func3 OutputAllAnalog;		// void OutputAllAnalog       (int Data1  , int Data2);
t_func  ClearAnalogChannel; 	// void ClearAnalogChannel    (int Channel           );
t_func0 ClearAllAnalog;			// void ClearAllAnalog        (                      );
t_func  SetAnalogChannel; 		// void SetAnalogChannel      (int Channel           );
t_func0 SetAllAnalog;			// void SetAllAnalog          (                      );
								// DO
t_func  WriteAllDigital;		// void WriteAllDigital       (int Data              );
t_func  ClearDigitalChannel;	// void ClearDigitalChannel   (int Channel           );
t_func0 ClearAllDigital;		// void ClearAllDigital       (                      );
t_func  SetDigitalChannel;		// void SetDigitalChannel     (int Channel           );
t_func0 SetAllDigital;			// void SetAllDigital         (                      );
								// DI
t_func5 ReadDigitalChannel;		// bool ReadDigitalChannel    (int Channel           );
t_func1 ReadAllDigital;			// int  ReadAllDigital        (                      );
								// counter
t_func4 ReadCounter;			// int  ReadCounter           (int CounterNr         );
t_func  ResetCounter;			// void ResetCounter          (int CounterNr         );
t_func3 SetCounterDebounceTime; // void SetCounterDebounceTime(int CounterNr, int DebounceTime);

HINSTANCE hDLL; // DLL handle
bool foundDLL                 = false;
bool foundCard                = false;
bool DisableOtherFunctionCall = false;
int  Channel = 8, DA1 = 0, DA2 = 0;


int init(){
#ifdef _WIN32
  hDLL = LoadLibrary("k8055d"); 
#endif 

//#ifdef 0
  //L is needed to differenciate
  //in some versions of visual studio
  //hDLL = LoadLibrary(L"k8055d");  
//#endif 

  if (hDLL != NULL){
	OpenDevice              =(t_func4) GetProcAddress(hDLL, "OpenDevice");
	if (!OpenDevice                  ){FreeLibrary(hDLL);return -2;}
	CloseDevice             =(t_func0) GetProcAddress(hDLL, "CloseDevice");
	if (!CloseDevice                 ){FreeLibrary(hDLL);return -2;}
	ReadAnalogChannel       =(t_func4) GetProcAddress(hDLL, "ReadAnalogChannel");
	if (!ReadAnalogChannel           ){FreeLibrary(hDLL);return -2;}
	ReadAllAnalog           =(t_func2) GetProcAddress(hDLL, "ReadAllAnalog");
	if (!ReadAllAnalog               ){FreeLibrary(hDLL);return -2;}
	OutputAnalogChannel     =(t_func3) GetProcAddress(hDLL, "OutputAnalogChannel");
	if (!OutputAnalogChannel         ){FreeLibrary(hDLL);return -2;}
	OutputAllAnalog         =(t_func3) GetProcAddress(hDLL, "OutputAllAnalog");
	if (!OutputAllAnalog             ){FreeLibrary(hDLL);return -2;}
	ClearAnalogChannel      =(t_func ) GetProcAddress(hDLL, "ClearAnalogChannel");
	if (!ClearAnalogChannel          ){FreeLibrary(hDLL);return -2;}
	ClearAllAnalog          =(t_func0) GetProcAddress(hDLL, "ClearAllAnalog");
	if (!ClearAllAnalog              ){FreeLibrary(hDLL);return -2;}
	SetAnalogChannel        =(t_func ) GetProcAddress(hDLL, "SetAnalogChannel");
	if (!SetAnalogChannel            ){FreeLibrary(hDLL);return -2;}
	SetAllAnalog            =(t_func0) GetProcAddress(hDLL, "SetAllAnalog");
	if (!SetAllAnalog                ){FreeLibrary(hDLL);return -2;}
	WriteAllDigital         =(t_func ) GetProcAddress(hDLL, "WriteAllDigital");
	if (!WriteAllDigital             ){FreeLibrary(hDLL);return -2;}
	ClearDigitalChannel     =(t_func ) GetProcAddress(hDLL, "ClearDigitalChannel");
	if (!ClearDigitalChannel         ){FreeLibrary(hDLL);return -2;}
	ClearAllDigital         =(t_func0) GetProcAddress(hDLL, "ClearAllDigital");
	if (!ClearAllDigital             ){FreeLibrary(hDLL);return -2;}
	SetDigitalChannel       =(t_func ) GetProcAddress(hDLL, "SetDigitalChannel");
	if (!SetDigitalChannel           ){FreeLibrary(hDLL);return -2;}
	SetAllDigital           =(t_func0) GetProcAddress(hDLL, "SetAllDigital");
	if (!SetAllDigital               ){FreeLibrary(hDLL);return -2;}
	ReadDigitalChannel      =(t_func5) GetProcAddress(hDLL, "ReadDigitalChannel");
	if (!ReadDigitalChannel          ){FreeLibrary(hDLL);return -2;}
	ReadAllDigital          =(t_func1) GetProcAddress(hDLL, "ReadAllDigital");
	if (!ReadAllDigital              ){FreeLibrary(hDLL);return -2;}
	ReadCounter             =(t_func4) GetProcAddress(hDLL, "ReadCounter");
	if (!ReadCounter                 ){FreeLibrary(hDLL);return -2;}
	ResetCounter            =(t_func ) GetProcAddress(hDLL, "ResetCounter");
	if (!ResetCounter                ){FreeLibrary(hDLL);return -2;}
	SetCounterDebounceTime  =(t_func3) GetProcAddress(hDLL, "SetCounterDebounceTime");
	if (!SetCounterDebounceTime      ){FreeLibrary(hDLL);return -2;}
	SetCurrentDevice        =(t_func4) GetProcAddress(hDLL, "SetCurrentDevice");
	if (!SetCurrentDevice            ){FreeLibrary(hDLL);return -2;}
	Version_                =(t_func0) GetProcAddress(hDLL, "Version");
	if (!Version_                     ){FreeLibrary(hDLL);return -2;}
	SearchDevices           =(t_func1) GetProcAddress(hDLL, "SearchDevices");
	if (!SearchDevices               ){FreeLibrary(hDLL);return -2;}
	return 0;				// ok
  }       
  return -1;					// error load DLL
}