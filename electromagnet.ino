#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_Circuit_Playground.h>
#include "Adafruit_Crickit.h"
#include "seesaw_servo.h"

Adafruit_Crickit crickit;
seesaw_Servo myservo(&crickit); 
seesaw_Servo myservo2(&crickit);

void setup() {
  Serial.begin(115200);
  Serial.println("1 Drive demo!");
  if(!crickit.begin()){
    Serial.println("ERROR!"); 
    while(1);
  }
  
  else Serial.println("Crickit started");
  myservo.attach(CRICKIT_SERVO1); //servo
  myservo2.attach(CRICKIT_SERVO2);
  //our default frequency is 1khz
  crickit.setPWMFreq(CRICKIT_DRIVE1, 1000); //electromagnet
}

void loop() {
  //turn all the way on
  crickit.analogWrite(CRICKIT_DRIVE1, CRICKIT_DUTY_CYCLE_OFF);
  CircuitPlayground.strip.setPixelColor(0, 0, 255, 0);
  CircuitPlayground.redLED(true);
  
  myservo.write(0);
  myservo2.write(0);
  
  CircuitPlayground.strip.show();

  //turn all the way off
  crickit.analogWrite(CRICKIT_DRIVE1, CRICKIT_DUTY_CYCLE_MAX);
  CircuitPlayground.strip.setPixelColor(0, 0, 0, 255);
  delay(3000);

  
  myservo.write(127);
  myservo2.write(127);

  delay(3000);
  
  CircuitPlayground.redLED(false);
  CircuitPlayground.strip.show();
  
  //delay(3000);
}void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
