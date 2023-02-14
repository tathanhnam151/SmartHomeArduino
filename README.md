#Voice-Controlled Light System for Smart Home

This project is a simulation of a voice-controlled light system for a smart home. With this system, you can control the lights in multiple rooms using voice commands from your phone. The system uses the HC-05 Bluetooth module to receive commands and an Arduino board to process and execute the commands. The code uses object-oriented programming concepts such as inheritance and polymorphism to create a class structure for the lights and devices in the system.

##Required Components
- Arduino board
- 2 LEDs
- HC-05 Bluetooth module
- Resistor
- Jumpers

##Connections
- Connect the HC-05 module to the Arduino board according to the pin mapping.
- Connect the two LEDs to the digital pins 3 and 4 on the Arduino board with a resistor.


##Code Overview

- The code consists of two classes: Device and Led.
- The Device class is a virtual class that has two virtual functions turnOn() and turnOff().
- The Led class is inherited from the Device class and implements the turnOn() and turnOff() functions by setting the digital output of the specified pin to either HIGH or LOW.
- The main code creates two objects of the Led class, ledOne and ledTwo, and assigns them to digital pins 3 and 4 respectively.
- The code also uses SoftwareSerial to communicate with the HC-05 module and receive the voice commands from a mobile phone.
- The loop function continuously reads the data from the HC-05 module and stores it in a string. If the string ends with the "#" symbol, it is compared with the four possible voice commands "*led one on#", "*led one off#", "*led two on#", "*led two off#". If a match is found, the corresponding LED is turned on or off.

##How to use
- Upload the code to the Arduino board.
- Pair the mobile phone with the HC-05 module.
- Send the voice commands "*led one on#", "*led one off#", "*led two on#", "*led two off#" from the mobile phone to control the LEDs.


##Conclusion
This code provides a simple way to control two LEDs with voice commands and demonstrate inheritance and polymorphism in C++.
