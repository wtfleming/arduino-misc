/*
  TMP36 temperature sensor 
  http://www.analog.com/static/imported-files/data_sheets/TMP35_36_37.pdf
*/


// Use analog input pin 0
const int temperatureAnalogInputPin = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  float voltage, degreesC, degreesF;

  // analogRead() returns a value between 0-1023
  // convert this to a float voltage between 0-5 volts
  voltage = analogRead(temperatureAnalogInputPin) * 0.004882814;


  // Note that the TMP36 has a 0.5V offset. The TMP35 and TMP37
  // do not. Do not subtract 0.5 if you use one of those.
  degreesC = (voltage - 0.5) * 100.0;
  
  degreesF = degreesC * (9.0/5.0) + 32.0;
  
  Serial.print("voltage: ");
  Serial.print(voltage);
  Serial.print("  deg C: ");
  Serial.print(degreesC);
  Serial.print("  deg F: ");
  Serial.println(degreesF);

   
  delay(1000);
}
