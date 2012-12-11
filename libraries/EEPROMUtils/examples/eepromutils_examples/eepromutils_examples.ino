#include <EEPROMUtils.h>

// Assumes 8 bit char, 16 bit int, 16 bit float
byte charAddr = 0;
byte intHighByteAddr = 1;
byte intLowByteAddr = 2;
byte floatHighByteAddr = 3;
byte floatLowByteAddr = 4;

int bytesAvailable;

void setup() {
  Serial.begin(9600);
  
  bytesAvailable = EEPROMUtils.totalBytesAvailable();
  EEPROMUtils.clear(bytesAvailable);
  
  // 1 byte char
  EEPROMUtils.write('s', charAddr);
  
  // 2 byte int
  EEPROMUtils.write(425, intHighByteAddr, intLowByteAddr);
  
  // 2 byte float
  EEPROMUtils.write(3.14f, floatHighByteAddr, floatLowByteAddr);
}




void loop() {
  Serial.print("Total EEPROM bytes available on board: ");
  Serial.println(bytesAvailable);

  char ch = EEPROMUtils.readChar(charAddr);
  Serial.print("char: ");
  Serial.println(ch);
  
  int i = EEPROMUtils.readInt(intHighByteAddr, intLowByteAddr);
  Serial.print("int: ");
  Serial.println(i);
  
  float f = EEPROMUtils.readFloat(floatHighByteAddr, floatLowByteAddr);
  Serial.print("float: ");
  Serial.println(f);
  
  delay(1000);
}
