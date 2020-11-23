/*
  Carrier.cpp - Library for Vending Machine code.
  Created by David Qual, October 20, 2019.
  Revised April 20, 2020
*/

// Define Carrier.h file
#ifndef Carrier_h
#define Carrier_h

#include <Arduino.h>

//extern "C" {}
#include <Servo.h>
#include <CLCD.h>

//define stepper mtor pins
#define vPin1 0
#define vPin2 1
#define hPin1 2
#define hPin2 3

//define limit switches for vertical/horizontal planes
#define vLimit 15
#define hLimit 14


Carrier::Carrier(){


 // Create Servo objects for Kookye 360 servo motors 
Servo servo1, servo2, servo3, servo4;   
 
//attach servo object on pins 4-7
 servo1.attach(4);
 servo2.attach(5);
 servo3.attach(6);
 servo4.attach(7);


}

//Functions to move item carrier Vertically

//function to move item carrier up on rails
void Carrier::Up(int steps)
{
   _steps = steps;
   digitalWrite(_vPin1, LOW);
      for (int x = 0; x < steps; x++) {
           digitalWrite(_vPin2, HIGH);
           delayMicroseconds(300);
           digitalWrite(_vPin2, LOW);
           delayMicroseconds(300);
     }   
}


//function to move item carrier down on rails
void Carrier::Down(int steps)
{
   _steps = steps;
    digitalWrite(_vPin1, LOW);
       for (int x = 0; x < steps; x++) {
           digitalWrite(_vPin2, HIGH);
           delayMicroseconds(300);
           digitalWrite(_vPin2, LOW);
           delayMicroseconds(300);      
     }
}

//Functions to move item carrier Horizontally


//function to move item carrier left on rails
void Carrier::Left(int steps)
{
   _steps = steps;
    digitalWrite(_hPin1, LOW);
       for (int x = 0; x < steps; x++) {
           digitalWrite(_hPin2, HIGH);
           delayMicroseconds(300);
           digitalWrite(_hPin2, LOW);
           delayMicroseconds(300);
    }
}

//function to move item carrier right on rails
void Carrier::Right(int steps)
{
   _steps = steps;
    digitalWrite(_hPin1, LOW);
       for (int x = 0; x < steps; x++) {
           digitalWrite(_hPin2, HIGH);
           delayMicroseconds(300);
           digitalWrite(_hPin2, LOW);
           delayMicroseconds(300);
    }
}


//function to return item carrier to home position
void Carrier::Home(int vLimit, int hLimit) 
{
	_vLimit = vLimit;
	hLimit = hLimit;
	
	digitalWrite(_vPin1, HIGH);
  while (true) {
    if (digitalRead(_vLimit) == LOW) { 
      Up(70);
      break;
    }
   
    digitalWrite(_vPin2, HIGH);
    delayMicroseconds(300);
    digitalWrite(_vPin2, LOW);
    delayMicroseconds(300);
  }
 
  digitalWrite(_hPin1, LOW);
  while (true) {
    if (digitalRead(_hLimit) == LOW) {
      Left(350);
      break;
    }
    digitalWrite(_hPin2, HIGH);
    delayMicroseconds(300);
    digitalWrite(_hPin2, LOW);
    delayMicroseconds(300);

  }
}


//Function to retreive item in bay A
void Carrier::getItemA() {

  LC1.clear();
  LC1.setCursor(0, 0);
  LC1.print("Delivering...");

  Up(4900);
  delay(200);

  Left(1700);
  delay(300);

  S1.writeMicroseconds(2000); // rotate
  delay(950);
  S1.writeMicroseconds(1500);  // stop
  delay(500);

  Right(1700);
  delay(200);
  Down(4900);

  LC1.clear();
  LC1.setCursor(0, 0);
  LC1.print("Item delivered!"); // Prints on the LCD
  delay(2000);
}


//Function to retreive item in bay B
void Carrier::getItemB() {

  LC1.clear();
  LC1.setCursor(0, 0);
  LC1.print("Delivering...");

  Up(4900);
  delay(200);

  S2.writeMicroseconds(2000); // rotate
  delay(950);
  S2.writeMicroseconds(1500);  // stop
  delay(500);
  Down(4900);

  LC1.clear();
  LC1.setCursor(0, 0);
  LC1.print("Item delivered!"); // Prints on the LCD
  delay(2000);
}


//Function to retreive item in bay C 
void Carrier::getItemC() {

  LC1.clear();
  LC1.setCursor(0, 0);
  LC1.print("Delivering...");

  Up(2200);
  delay(200);
  Left(1700);
  delay(300);

  // Rotate the helix, push the selected item
  S3.writeMicroseconds(2000); // rotate
  delay(950);
  S3.writeMicroseconds(1500);  // stop
  delay(500);

  // Move the container back to starting position
  Right(1700);
  delay(200);
  Down(2200);

  // Clear the display
  LC1.clear();
  LC1.setCursor(0, 0);
  LC1.print("Item delivered!"); // Prints on the LCD
  delay(2000);
}


//Function to retreive item in bay D 
void Carrier::getItemD(){

  LC1.clear();
  LC1.setCursor(0, 0);
  LC1.print("Delivering...");
  
  Up(2200);
  delay(200);

  S4.writeMicroseconds(2000); // rotate
  delay(950);
  S4.writeMicroseconds(1500);  // stop
  delay(500);
  Down(2200);

  LC1.clear();
  LC1.setCursor(0, 0);
  LC1.print("Item delivered!"); // Prints on the LCD
  delay(2000);

}


	
}
#endif
