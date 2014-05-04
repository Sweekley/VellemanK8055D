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
#include "K8055D_new.h"
#include <string>

using namespace std;

void TestButtons(){
	system("cls");
	int	i = 0;
	bool end = true;
	string readkbrd = " ";
	cout << "This tests the button functions on K8055 board. \n";
	cout << "To exit k \n.";

	while (true)
	{
		i = ReadAllDigital();
		cout << "Digital Input: " << i << " \n";
		if ((i & 1) > 0) cout << "button (Inp1) pressed.\n";
		if ((i & 2) > 0) cout << "button (Inp2) pressed.\n";
		if ((i & 4) > 0) cout << "button (Inp3) pressed.\n";
		if ((i & 8) > 0) cout << "button (Inp4) pressed.\n";
		if ((i & 16) > 0) cout << "button (Inp3) pressed.\n";
		if ((cin >> readkbrd.c_str) == "k"){
			end = false; 
		}

	}




	


}

