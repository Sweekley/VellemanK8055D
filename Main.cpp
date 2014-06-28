/*
============================================================================
Name        : Main.cpp
Author      : Scott Weekley
Version     : 0.0A
Description : Velleman K8055D
============================================================================
* Enceladus Confidential
* 2013 Enceladus Technologies
* All Rights Reserved.
* ___________________________________________________________________
* NOTICE:
* The intellectual and technical concepts contained
* herein are proprietary to Enceladus Technologies.
* Dissemination of this information or reproduction of this material
* is strictly forbidden unless prior written permission is obtained
* from Enceladus Technologies.
*/

//Note: Do not include k8055dTest.cpp in your project 


//#include "K8055D_new.h";
//#include "K8055dTest.h"
#include <Windows.h>
#include <iostream>

#include "k8055dTest.cpp"

using namespace std;


int main(){
	//variables 
	int report = 0, count = 0, CardAddr = 0, Responce = 3;
	bool toggle = false;
	long lngReturn = 0, lngValue = 0;

	cout << "These following test functions were \n";
	cout << "created by Enceladus Technologies \n";
	cout << "And are free for use as long as recognition \n";
	cout << "is given. \n"; 
	//required initialization for functions to work 
	init();

	//checking version type 
	Version_();

	//opening the device 
	Responce = OpenDevice(CardAddr);
	
	//deciding what to do if the card is or isn't there 
	if (Responce == CardAddr){
		cout << "Card has been connected" << endl;
		system("pause");

		//clear all 
		cout << "Clearing All Analog Connections \n" << endl;
		ClearAllAnalog();
		cout << "Clearing All Digital Connections \n" << endl;
		ClearAllDigital();
		//if card shows up then begin
		system("pause"); 
		cout << "Tests Inp Buttons";
		TestButtons(); 
		cout << "Button Test completed \n"; 

		system("pause");

		//This tests Out1 through Out8
		cout << "Tests Out Digitial Outputs";
		TestAllDI(50); 

		//Tests PulseWith AD's 
		cout << "Testing PWM";
		TestPWM(1); 
	}

	else cout << "No card found check again." << endl;
	system("pause"); 

	system("cls"); 
	cout << "Thank you for using Enceladus Technologies \n";
	cout << "K8055D Test Functions \n";
	cout << "If you have any questions email the following address. \n";
	cout << "\nSweekley@enceladus.mygbiz.com \n\n";
	cout << "Have a nice day. \n"; 

	ClearAllAnalog();
	ClearAllDigital();
	CloseDevice(); 
	//system("pause");
}

//so now all the functions exist using K8055 debug. But we have to figure out how to get access in the main. 

//Currently using K8055_USB as an example. 
//not init must be run first! That solves the heap problem. 

//http://msdn.microsoft.com/en-us/library/windows/desktop/ms685032%28v=vs.85%29.aspx
//The line above may take care of the blinking screen issue on the console 