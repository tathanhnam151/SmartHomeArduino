#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

const int led1 = 3;
const int led2 = 4;

String inStr;

class Device
{
 public:
  virtual void turnOn() = 0;
  virtual void turnOff() = 0;
};

class Led : public Device
{
  int pin;
 public:
  Led(int p)
  {
    pin = p;
    pinMode(pin, OUTPUT);
  }
  void turnOn()
  {
    digitalWrite(pin, HIGH);
  }
  void turnOff()
  {
    digitalWrite(pin, LOW);
  }
};

Led ledOne = Led(led1);
Led ledTwo = Led(led2);

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  while (mySerial.available() > 0) {
    char inChar = (char)mySerial.read();
    inStr += inChar;
    if (inStr.endsWith("#")) {
      if (!strcmp(inStr.c_str(), "*led one on#")) {
        ledOne.turnOn();
      }
      if (!strcmp(inStr.c_str(), "*led one off#")) {
        ledOne.turnOff();
      }
      if (!strcmp(inStr.c_str(), "*led two on#")) {
        ledTwo.turnOn();
      }
      if (!strcmp(inStr.c_str(), "*led two off#")) {
        ledTwo.turnOff();
      }
      inStr = "";
    }
  }
}
