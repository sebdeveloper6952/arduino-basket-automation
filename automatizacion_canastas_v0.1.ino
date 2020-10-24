#define PULSE_PIN 7
#define DIR_PIN 6
#define BUTTON_PIN 8
s
#include <Stepper.h>

const int stepsPerRevolution = 300;
Stepper myStepper(stepsPerRevolution, 6, 7);

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(200);
  pinMode(5, OUTPUT);
  pinMode(8, OUTPUT);
  //delay(3000);
}

void loop() {
  // step one revolution  in one direction:
  if (digitalRead(8) == 1) {
    digitalWrite(5, HIGH);
    myStepper.step(1);
  }
  else
    digitalWrite(5, LOW);
  
}
