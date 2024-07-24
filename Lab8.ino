//Lab #8 Ryan Murphy 
 
#include <SoftwareSerial.h> #include <HX711.h> 
#include <SoftwareSerial.h> 
#include <HX711.h> 
#define calibration 0 
#define measurement 1 
 unsigned long loopDelay = 0; unsigned int machineState = 1; float calibrationFactor = 20000; 
 
HX711 loadCell; //Declare the loadcell varaible of type HX711 
SoftwareSerial serialLCD = SoftwareSerial(-1, 7, 1); //Declare the SoftwareSerial object const char clearScreen[5] = {0xFE, 0x01, 0xFE, 0x80, 0x00}; //Define the clear screen command for the LCD void setup() //Setup Code...Initialize Hardware 
{   pinMode(7, OUTPUT);   digitalWrite(7, LOW);   serialLCD.begin(9600); //Buad rate   serialLCD.print(clearScreen);   loadCell.begin(3,2);   loadCell.set_scale(calibrationFactor); 
  pinMode(13, OUTPUT); //Pin to control on-board flashing LED 
  Serial.begin(9600); //Serial to terminal window...9600baud 
  Serial.println("ECE345 Experiment 8"); //Print initial notes to PC serial terminal 
  Serial.println("Load Cell Measurement Lab"); 
  Serial.println("Entering Measurement Mode"); 
}  
void loop() 
{ 
  unsigned char serialInput = 0; 
     if (Serial.available()) 
  { 
    serialInput = Serial.read(); 
  }      if ((serialInput == 'T') || (serialInput == 't')) //Checks if T or t 
  { 
    Serial.println("Load Cell Has Been Tared");     loadCell.tare(); //Tare command 
  }      switch(machineState) 
  {     case calibration: 
      if ((serialInput == 'M') || (serialInput == 'm')) 
      { 
        Serial.println("Going to Measurement Mode");         machineState = measurement; //Sets to measurement mode 
      }       else if ((serialInput == 'A') || (serialInput == 'a')) //Checks if A or a 
      { 
        calibrationFactor += 10; //Decreased by 10 
        Serial.print("New Calibration Value = "); 
        Serial.println(calibrationFactor); 
      }       else if ((serialInput == 'Z') || (serialInput == 'z')) //Checks if Z or z 
      { 
        calibrationFactor -= 10; //Increaseed by 10 
        Serial.print("New Calibration Value = "); 
        Serial.println(calibrationFactor); 
      }       else if ((serialInput == 'S') || (serialInput == 's')) //Checks if S or s 
      { 
        calibrationFactor += 100; //Decreased by 100 
        Serial.print("New Calibration Value = "); 
        Serial.println(calibrationFactor); 
      }       else if ((serialInput == 'X') || (serialInput == 'x')) //Checks if X or x 
      { 
        calibrationFactor -= 100; //Increased by 100 
        Serial.print("New Calibration Value = "); 
        Serial.println(calibrationFactor);  
      } 
      loadCell.set_scale(calibrationFactor);       break;     case measurement: 
      if ((serialInput == 'C') || (serialInput == 'c')) //Checks if C or c 
      { 
        Serial.println("Going to Calibration Mode");          machineState = calibration; //Sets to calibration mode 
      }       break;     default:       break;   }   loopDelay++; 
  if (loopDelay > 40000) 
  {     loopDelay = 0; //Sets loopDelay to 0     digitalWrite(13, !digitalRead(13)); //Update LCD with load cell reading     serialLCD.print(clearScreen); //Clear LCD screen     serialLCD.print(loadCell.get_units(), 3); //Display weight with 3 decimal places 
  } 
} 
//The IDE does not automatically load all possible libraries to avoid unnecessary memory usage, increased compile times and potential conflicts between libraries 
 
 

