#include <SoftwareSerial.h>
#include <HX711.h>

#define calibration 0
#define measurement 1

unsigned long loopDelay = 0;
unsigned int machineState = 1;
float calibrationFactor = 20000;

//Setup Code...Initialize Hardware
void setup()
{
  pinMode(13, OUTPUT);//Pin to control on-board flashing LED
  Serial.begin(9600);//Serial to terminal window...9600baud
  //Print initial notes to PC serial terminal
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println("ECE345 Experiment 8");
  Serial.println("Load Cell Measurement Lab");
  Serial.println("Entering Measurement Mode");
}

void loop()
{
  unsigned char serialInput = 0;
  
  if (Serial.available())
  {
    serialInput = Serial.read();
  }
  
  if ((serialInput == 'T') || (serialInput == 't'))
  {
    Serial.println("Load Cell Has Been Tared");
  }
  
  switch(machineState)
  {
    case calibration:
      if ((serialInput == 'M') || (serialInput == 'm'))
      {
        Serial.println("Going to Measurement Mode");
        machineState = measurement;
      }
      else if ((serialInput == 'A') || (serialInput == 'a'))
      {
        Serial.print("New Calibration Value = ");
        Serial.println(calibrationFactor);
      }
      else if ((serialInput == 'Z') || (serialInput == 'z'))
      {
        Serial.print("New Calibration Value = ");
        Serial.println(calibrationFactor);
      }
      else if ((serialInput == 'S') || (serialInput == 's'))
      {
        Serial.print("New Calibration Value = ");
        Serial.println(calibrationFactor);
      }
      else if ((serialInput == 'X') || (serialInput == 'x'))
      {
        Serial.print("New Calibration Value = ");
        Serial.println(calibrationFactor);
      }
      break;
    case measurement:
      if ((serialInput == 'C') || (serialInput == 'c'))
      {
        Serial.println("Going to Calibration Mode");
        machineState = calibration;
      }
      break;
    default:
      break;
  }
  loopDelay++;
  if (loopDelay > 40000)
  {
    loopDelay = 0;
    digitalWrite(13, !digitalRead(13));
  }
}
