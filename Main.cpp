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


#include "K8055D_new.h"
#include <Windows.h>
#include <iostream>

using namespace std;

void test(){



	system("pause");
	system("cls");
	cout << "Testing Now begins" << endl; 
}//end test 


int main(){
	//variables 
	int report = 0, count = 0, CardAddr = 0, Responce = 3;
	bool toggle = false;
	long lngReturn = 0, lngValue = 0;
	init();
	//Declare function
	//This is where we try to attach the item
	Version_();
	Responce = OpenDevice(CardAddr);
	//system("pause");
	if (Responce == CardAddr){
		cout << "Card has been connected" << endl;
		test();
		//if card shows up then begin 
	}
	else cout << "No card found check again." << endl;
	system("pause");

	//clear all 
	cout << "Clearing All Analog Connections" << endl;
	ClearAllAnalog();
	cout << "Clearing All Digital Connections" << endl;
	ClearAllDigital();


}

//so now all the functions exist using K8055 debug. But we have to figure out how to get access in the main. 

//Currently using K8055_USB as an example. 
//not init must be run first! That solves the heap problem. 

//http://msdn.microsoft.com/en-us/library/windows/desktop/ms685032%28v=vs.85%29.aspx
//The line above may take care of the blinking screen issue on the console 