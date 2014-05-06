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
/* Note this is an old style non-oop class
*/

#include "K8055dTest.h"
//#include "K8055D_new.h"
#include <string>
//#include <fstream>
#include <iostream>
//#include <istream>
//#include <ostream>
#include <Windows.h>


using namespace std;

void TestButtons(){
	system("cls");
	int	i = 0;
	bool end = false;
	string readkbrd = " ";
	cout << "This tests the button functions on K8055 board. \n";
	cout << "To exit the ESC button. \n";

	while (!end){
		//reads digital inputs 
		i = ReadAllDigital();

		if ((i & 1) > 0) {
			cout << "Digital Input: " << i << " \n";
			cout << "button (Inp1) pressed.\n";
		}
		if ((i & 2) > 0) {
			cout << "Digital Input: " << i << " \n";
			cout << "button (Inp2) pressed.\n";
		}
		if ((i & 4) > 0){
			cout << "Digital Input: " << i << " \n";
			cout << "button (Inp3) pressed.\n";
		}

		if ((i & 8) > 0) {
			cout << "Digital Input: " << i << " \n";
			cout << "button (Inp4) pressed.\n";
		}

		if ((i & 16) > 0) {
			cout << "Digital Input: " << i << " \n";
			cout << "button (Inp3) pressed.\n";
		}
		//end if its true
		if (GetAsyncKeyState(VK_ESCAPE))end = true; 
	}  
}

void TestAllDI(int increment){
	//Tests DI functionality
	ClearAllDigital();
	int i = 0; 
	system("cls"); 
	cout << "Testing DO lights \n"; 
	cout << "Press the ESC button to end the test \n"; 
	while (!GetAsyncKeyState(VK_ESCAPE)){
		ClearDigitalChannel(i);
		i++;
		if (i == 9) i = 1;
		SetDigitalChannel(i);
		Sleep(increment);
	}
}

void TestPWM(int increment){
	ClearAllDigital();

	cout << "Testing DO lights \n";
	//255 is maximum value for a 2^8 ranged 
	// output 
	int i1 = 0, i2 = 255, input1 = 1, input2 = 1;

	while (!GetAsyncKeyState(VK_ESCAPE)){
		i1 += input1; 
		i2 -= input2;
		//switch sign on input 
		if ((i1 == 0) || (i1 == 255)) input1 = -input1;
		if ((i2 == 0) || (i2 == 255)) input2 = -input2;
		OutputAnalogChannel(1, i1);
		OutputAnalogChannel(2, i2);
		Sleep(increment);
	}



}


