//this is following the devC example 

//#include "K8055.h"
//#include "K8055_C.h"
#include "K8055D_new.h"
#include <Windows.h>
#include <iostream>

using namespace std;

//HINSTANCE hDLL;

void test(){

	//clear all 
	system("Pause"); 
	cout << "Clearing All Analog Connections" << endl;
	ClearAllAnalog();
	cout << "Clearing All Digital Connections" << endl;
	ClearAllDigital(); 

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
}

//so now all the functions exist using K8055 debug. But we have to figure out how to get access in the main. 

//Currently using K8055_USB as an example. 
//not init must be run first! That solves the heap problem. 

//http://msdn.microsoft.com/en-us/library/windows/desktop/ms685032%28v=vs.85%29.aspx
//The line above may take care of the blinking screen issue on the console 