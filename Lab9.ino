unsigned long loopDelay; // Declare the global variable


void setup() // Initialize digital pins as outputs
{
  pinMode(6, OUTPUT);
  pinMode(13, OUTPUT);
}


void loop()
{
  loopDelay++; // Increment the loopDelay counter
    if (loopDelay > 40000) // Check if loopDelay exceeds the threshold
    {
    loopDelay = 0; // Reset the loopDelay counter    
    digitalWrite(13, !digitalRead(13)); // Toggle the state of pin 13
  }
  analogWrite(6, analogRead(0) / 4);
}
