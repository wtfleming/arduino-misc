#include <EEPROM.h>

// Assumes 8 bit char, 16 bit int, 16 bit float

byte charAddr = 0;
byte intHighByteAddr = 1;
byte intLowByteAddr = 2;
byte floatHighByteAddr = 3;
byte floatLowByteAddr = 4;

union data {
  float f;
  int i;
} convert;


void writeInt(int i, int highByteAddr, int lowByteAddr) {
  EEPROM.write(highByteAddr, highByte(i));
  EEPROM.write(lowByteAddr, lowByte(i));
}

void setup() {
  Serial.begin(9600);
  
  // Clear EEPROM
  //for (int x = 0; x < 1023; ++x) {
  //  EEPROM.write(x, 0);
  //}
  
  // 1 byte char
  EEPROM.write(charAddr, 'h');
  
  // 2 byte int
  writeInt(455, intHighByteAddr, intLowByteAddr);
  
  // 2 byte float
  convert.f = 5.71;
  writeInt(convert.i, floatHighByteAddr, floatLowByteAddr);
  
}




void loop() {
  // char
  char ch = EEPROM.read(charAddr);
  Serial.print("char: ");
  Serial.println(ch);
  
  // int
  byte high = EEPROM.read(intHighByteAddr);
  byte low = EEPROM.read(intLowByteAddr);

  int i = (high << 8) + low;  
  Serial.print("int: ");
  Serial.println(i);
  
  // float
  high = EEPROM.read(floatHighByteAddr);
  low = EEPROM.read(floatLowByteAddr);

  convert.i = (high << 8) + low;  
  Serial.print("float: ");
  Serial.println(convert.f);
  
  
  
  delay(1000);
}
