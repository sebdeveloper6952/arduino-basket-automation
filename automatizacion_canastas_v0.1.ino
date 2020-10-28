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

// pin for foot switch
#define BUTTON_PIN 8

// stepper configuration
#define STEPS_PER_REV 300
#define STEPPER_SPEED 200
#define STEPPER_ONE_STEP 1
#define ONE_REV 360
#define HALF_REV ONE_REV / 2
#define OFF_TIME_THRES 250
#define OFF_TIME_DELAY 100

// testing return to initial angle functionality
unsigned int cur_steps = 0;
unsigned int off_start_time;
unsigned int off_time = 0;

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

  // TODO: testing, save initial time
  // off_start_time = millis();
}

void loop()
{
  // turn the motor 1 step when foot button is pressed;
  // otherwise, turn the motor off by setting the ENA pin to LOW.
  if (digitalRead(BUTTON_PIN) == HIGH)
  {
    // set the stepper motor free and advance 1 step.
    digitalWrite(ENA_PIN, HIGH);
    stepper.step(STEPPER_ONE_STEP);

    // TODO: testing: increase steps and reset start time.
    // cur_steps = (cur_steps + 1) % ONE_REV;
    // off_start_time = 0;
  }
  // else if (off_start_time > OFF_TIME_THRES)
  // {
  //   // TODO: testing return to initial angle
  //   delay(OFF_TIME_DELAY);
  //   digitalWrite(ENA_PIN, HIGH);
  //   if (cur_steps <= HALF_REV)
  //     stepper.step(-cur_steps);
  //   else
  //     stepper.step(ONE_REV - cur_steps);
  //   cur_steps = 0;
  //   digitalWrite(ENA_PIN, LOW);
  // }
  // else if (off_start_time == 0)
  // {
  //   // TODO: store time when button is lifted
  //   off_start_time = millis();
  // }
  else
  {
    // set the stepper motor locked
    digitalWrite(ENA_PIN, LOW);

    // TODO: increase off time
    // off_time += millis() - off_start_time;
  }
}