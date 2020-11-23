/*
  Carrier.h - Library for Vending Machine Operation.
  Created by David Qual, October 20, 2019.
  Revised on April 20, 2020
*/

//initial definitions
extern "C" {
#ifndef Carrier_h
#define Carrier_h
#include <Arduino.h>
#include <Servo.h>
}

//Declare functions and variables for Carrier Class
class Carrier
{
    //Declare public functions and parameters for Carrier Class 
	public:
       Carrier();
       void Up(int steps);
       void Down(int steps);
       void Left(int steps);
       void Right(int steps);
       void Home(int vLimit, int hLimit);
       void getItemA();
       void getItemB();
       void getItemC();
       void getItemD();

      
    //Declare private variables for Carrier Class 
	private:
	int _vPin1;
	int _vPin2;
	int _hPin1;
	int _hPin2;
	int _steps;
	int _vLimit;
	int _hLimit;
	
	
};
#endif