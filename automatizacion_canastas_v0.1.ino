/*
 Arduino Process Automation

 Created 23 October 2020
 by Alejandro Medina, Sebastian Arriola

*/

#include <Stepper.h>

// pins for controlling the STM5045
#define PULSE_PIN 7
#define DIR_PIN 6
#define ENA_PIN 5

// pin bor foot switch
#define BUTTON_PIN 8

// stepper configuration
#define STEPS_PER_REV 300
#define STEPPER_SPEED 200
#define STEPPER_ONE_STEP 1

// stepper settings
Stepper stepper(STEPS_PER_REV, DIR_PIN, PULSE_PIN);

void setup()
{
  // set STM5045 ENA pin to output
  pinMode(ENA_PIN, OUTPUT);
  // set foot button pin to output
  pinMode(BUTTON_PIN, OUTPUT);

  // stepper fixed speed configuration
  stepper.setSpeed(STEPPER_SPEED);
}

void loop()
{
  // turn the motor 1 step when foot button is pressed;
  // otherwise, turn the motor off by setting the ENA pin to LOW.
  if (digitalRead(BUTTON_PIN) == 1)
  {
    digitalWrite(ENA_PIN, HIGH);
    myStepper.step(STEPPER_ONE_STEP);
  }
  else
  {
    digitalWrite(ENA_PIN, LOW);
  }
}
