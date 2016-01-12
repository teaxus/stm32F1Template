#include"TSTools.h"
#include<stdio.h>
#include"TSLibConfig.h"

#include"DriverA2051.h"


#define A2051_SCLK 2
#define A2051_SDIO 3
#define A2051_PD 4

//int dumpWidth = 256; // Number of pixels to read for each frame.
//byte frame[256];

void setup() {
//  Serial.begin(115200);

//  reset();
//  byte productId = readRegister(REG_PRODUCT_ID);
//  byte revisionId = readRegister(REG_REVISION_ID);
//  Serial.print("Found productId ");
//  Serial.print(productId, HEX);
//  Serial.print(", rev. ");
//  Serial.print(revisionId, HEX);
//  Serial.println(productId == 0x02 ? " OK." : " Unknown productID. Carry on.");

//  byte config = readRegister(REG_CONFIG_BITS);
//  config |= B00000001; // Don't sleep (LED always powered on).
//  writeRegister(REG_CONFIG_BITS, config);
}

//void loop() {
//  // Allows to set the dump window by sending the number of lines to read via the serial port.
//  if(Serial.available() > 0) {
//    dumpWidth = 16 * Serial.read();
//    dumpWidth = constrain(dumpWidth, 0, 256);
//  }

//  readRegister(REG_MOTION); // Freezes DX and DY until they are read or MOTION is read again.
//  char dx = readRegister(REG_DELTA_X);
//  char dy = readRegister(REG_DELTA_Y);
//  Serial.print("DELTA:");
//  Serial.print(dx, DEC);
//  Serial.print(" ");
//  Serial.println(dy, DEC);

//  if( dumpWidth > 0 )
//    dumpFrame();
//}

//void dumpFrame() {
//  byte config = readRegister(REG_CONFIG_BITS);
//  config |= B00001000; // PixDump
//  writeRegister(REG_CONFIG_BITS, config);

//  int count = 0;
//  do {
//    byte data = readRegister(REG_DATA_OUT_LOWER);
//    if( (data & 0x80) == 0 ) { // Data is valid
//      frame[count++] = data;
//    }
//  } 
//  while (count != dumpWidth);

//  config = readRegister(REG_CONFIG_BITS);
//  config &= B11110111;
//  writeRegister(REG_CONFIG_BITS, config);

//  Serial.print("FRAME:");
//  for(int i = 0; i < dumpWidth; i++) {
//    byte pix = frame[i];
//    if( pix < 0x10 )
//      Serial.print("0");
//    Serial.print(pix, HEX);
//  }
//  Serial.println();
//}

//void reset() {
//  pinMode(SCLK, OUTPUT);
//  pinMode(SDIO, INPUT);
//  pinMode(PD, OUTPUT);
//  digitalWrite(SCLK, LOW);
//  digitalWrite(PD, HIGH);
//  delayMicroseconds(1);
//  digitalWrite(PD, LOW);
//}

//byte readRegister(byte address) {
//  pinMode (SDIO, OUTPUT);

//  for (byte i=128; i >0 ; i >>= 1) {
//    digitalWrite (SCLK, LOW);
//    digitalWrite (SDIO, (address & i) != 0 ? HIGH : LOW);
//    digitalWrite (SCLK, HIGH);
//  }

//  pinMode (SDIO, INPUT);

//  delayMicroseconds(100); // tHOLD = 100us min.

//  byte res = 0;
//  for (byte i=128; i >0 ; i >>= 1) {
//    digitalWrite (SCLK, LOW);
//    digitalWrite (SCLK, HIGH);
//    if( digitalRead (SDIO) == HIGH )
//      res |= i;
//  }

//  return res;
//}

void writeRegister(byte address, byte data) {
  address |= 0x80; // MSB indicates write mode.
//  pinMode (SDIO, OUTPUT);

//  for (byte i = 128; i > 0 ; i >>= 1) {
//    digitalWrite (SCLK, LOW);
//    digitalWrite (SDIO, (address & i) != 0 ? HIGH : LOW);
//    digitalWrite (SCLK, HIGH);
//  }

//  for (byte i = 128; i > 0 ; i >>= 1) {
//    digitalWrite (SCLK, LOW);
//    digitalWrite (SDIO, (data & i) != 0 ? HIGH : LOW);
//    digitalWrite (SCLK, HIGH);
//  }

//  delayMicroseconds(100); // tSWW, tSWR = 100us min.
}
