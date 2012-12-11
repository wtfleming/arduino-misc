#ifndef EEPROMUTILS_h
#define EEPROMUTILS_h

#include <inttypes.h>

// Be aware each byte of EEPROM has a lifetime of only 100,000 write/erase cycles.
// Might want to use something like http://playground.arduino.cc/Code/EEPROMWriteAnything instead of this library
class EEPROMUtilsClass {
  public:
    void write(char i, uint8_t addr);
    void write(int i, uint8_t highByteAddr, uint8_t lowByteAddr);
    void write(float f, uint8_t highByteAddr, uint8_t lowByteAddr);

    char readChar(uint8_t addr);
    int readInt(uint8_t highByteAddr, uint8_t lowByteAddr);
    float readFloat(uint8_t highByteAddr, uint8_t lowByteAddr);

    int totalBytesAvailable();
    void clear(int numBytes);

  private:
    union data {
      float f;
      int i;
    } mConvert;


    uint8_t read(int addr);
    void write(int addr, uint8_t value);
};

extern EEPROMUtilsClass EEPROMUtils;

#endif // EEPROMUTILS_h

