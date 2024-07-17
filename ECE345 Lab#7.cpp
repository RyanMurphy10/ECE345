int loopCounter(0);
unsigned long loopDelay = 0;


void setup()
{
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}


void loop()
{
  loopCounter++;
  digitalWrite(13, !digitalRead(13));
  loopDelay++;
  if (loopDelay > 50000)
  {
    loopDelay = 0;
    digitalWrite(8, !digitalRead(9));
    Serial.print("Analog Measurement Number ");
    Serial.print(loopCounter);
    Serial.print(".Value = ");
    float adcResult = analogRead(0) * 5.0 / 1023.0;
    Serial.print(adcResult, 3);
    Serial.println(" Volts");
  }
}


