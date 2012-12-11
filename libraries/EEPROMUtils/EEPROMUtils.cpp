#include <avr/eeprom.h>
#include "Arduino.h"
#include <EEPROMUtils.h>



  void EEPROMUtilsClass::write(char c, uint8_t addr) {
    write(addr, c);
  }

  void EEPROMUtilsClass::write(int i, uint8_t highByteAddr, uint8_t lowByteAddr) {
    write(highByteAddr, highByte(i));
    write(lowByteAddr, lowByte(i));
  }

  void EEPROMUtilsClass::write(float f, uint8_t highByteAddr, uint8_t lowByteAddr) {
    mConvert.f = f;
    write(mConvert.i, highByteAddr, lowByteAddr);
  }
  
  
  char EEPROMUtilsClass::readChar(uint8_t addr) {
    return read(addr);
  }

  int EEPROMUtilsClass::readInt(uint8_t highByteAddr, uint8_t lowByteAddr) {
    byte high = read(highByteAddr);
    byte low = read(lowByteAddr);
    return (high << 8) + low;
  }
  
  float EEPROMUtilsClass::readFloat(uint8_t highByteAddr, uint8_t lowByteAddr) {
    mConvert.i = readInt(highByteAddr, lowByteAddr);
    return mConvert.f;
  }

  void EEPROMUtilsClass::clear(int numBytes) {
    for (int x = 0; x < (numBytes - 1); ++x) {
      write(x, 0);
    }
  }



  // Determine how many bytes of EEPROM are available on this board
  // A return value of -1 indicates a board size we did not expect to see
  // http://arduino.cc/en/Main/Boards
  int EEPROMUtilsClass::totalBytesAvailable() {
    const int MAGICNUMBER = 33;
    const int BASENUMBER = 66;
  
    write(0, BASENUMBER);
    write(512, MAGICNUMBER);
    byte b = read(0);
    if (b == MAGICNUMBER) {
      return 512;
    }
  
    write(0, BASENUMBER);
    write(1024, MAGICNUMBER);
    b = read(0);
    if (b == MAGICNUMBER) {
      return 1024;
    }

    write(0, BASENUMBER);
    write(4096, MAGICNUMBER);
    b = read(0);
    if (b == MAGICNUMBER) {
      return 4096;
    }

    return -1;
  }


  // Private
  uint8_t EEPROMUtilsClass::read(int addr) {
	  return eeprom_read_byte((unsigned char *) addr);
  }

  void EEPROMUtilsClass::write(int addr, uint8_t value) {
	  eeprom_write_byte((unsigned char *) addr, value);
  }



EEPROMUtilsClass EEPROMUtils;
