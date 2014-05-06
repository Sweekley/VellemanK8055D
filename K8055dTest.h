#ifndef TEST_H   // Avoid redeclaring class Presidents.
#define TEST_H   // This code is compiled only once

#include "K8055D_new.h"

void TestButtons();
//This test does not currently include debounce

void TestAllDI(int increment);
//a quick test for all digital outputs 
//int increment is the time in milliseconds until next switch
//I.E: increment = 10 => 10 milliseconds between switch 

void TestPWM(int increment);
//This tests the PWM for both lights
//Increment controls the speed of the blinking
#endif 