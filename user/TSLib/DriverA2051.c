#include"TSLibConfig.h"
#include"DriverA2051.h"
#include<stm32f10x.h>


TSIOOperation operation_SDIO;
TSIOOperation operation_SCLK;
TSIOOperation operation_PD;

#define A2051_SDIO GPIO_Pin_0
#define A2051_SCLK GPIO_Pin_1
#define A2051_PD GPIO_Pin_2

#define A2051_SDIO_Read operation_SDIO.ReadBit(&operation_SDIO.struct_GPIO)
#define A2051_SDIO_H operation_SDIO.High(&operation_SDIO.struct_GPIO)
#define A2051_SDIO_L operation_SDIO.Low(&operation_SDIO.struct_GPIO)

#define A2051_SCLK_H operation_SDIO.High(&operation_SCLK.struct_GPIO)
#define A2051_SCLK_L operation_SDIO.Low(&operation_SCLK.struct_GPIO)

#define A2051_PD_H operation_SDIO.High(&operation_PD.struct_GPIO)
#define A2051_PD_L operation_SDIO.Low(&operation_PD.struct_GPIO)

//int dumpWidth = 256; // Number of pixels to read for each frame.
//byte frame[256];
void reset(void);
byte readRegister(byte address);
void writeRegister(byte address, byte data);

void setup() {
  byte productId;
  byte revisionId;
  byte config;
	
	//初始化这3个IO端口
	TSStandardIOInit(GPIOA,A2051_SCLK,GPIO_Mode_Out_OD,GPIO_Speed_2MHz,&operation_SCLK);
	TSStandardIOInit(GPIOA,A2051_SDIO,GPIO_Mode_Out_OD,GPIO_Speed_2MHz,&operation_SDIO);
	TSStandardIOInit(GPIOA,A2051_PD,GPIO_Mode_Out_OD,GPIO_Speed_2MHz,&operation_PD);

	reset();
	productId = readRegister(REG_PRODUCT_ID);
	revisionId = readRegister(REG_REVISION_ID);
	printf("Found productId \r\n");
	printf("productId=%X\r\n",productId);
	printf(", rev. \r\n");
	printf("revisionId=%X\r\n",revisionId);
	printf("%s\r\n",productId == 0x02 ? " OK." : " Unknown productID. Carry on.");
	
	
	config = readRegister(REG_CONFIG_BITS);
	config |= 0x00000001; // Don't sleep (LED always powered on).
  writeRegister(REG_CONFIG_BITS, config);
	
	
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

void reset(void) {
	A2051_SCLK_L;
	A2051_PD_H;
	delay_us(10);
	A2051_PD_L;
	
//  pinMode(SCLK, OUTPUT);
//  pinMode(SDIO, INPUT);
//  pinMode(PD, OUTPUT);
//  digitalWrite(SCLK, LOW);
//  digitalWrite(PD, HIGH);
//  delayMicroseconds(1);
//  digitalWrite(PD, LOW);
}


byte readRegister(byte address) {
  byte res = 0;
	byte i=0;
//  pinMode (SDIO, OUTPUT);

  for (i=128; i >0 ; i >>= 1) {
		A2051_SCLK_L;
		if((address & i) != 0){
			A2051_SDIO_H;
		}
		else{
			A2051_SDIO_L;
		}
		A2051_SCLK_H;
//    digitalWrite (SCLK, LOW);
//    digitalWrite (SDIO, (address & i) != 0 ? HIGH : LOW);
//    digitalWrite (SCLK, HIGH);
  }

//  pinMode (SDIO, INPUT);

	delay_us(100);
//  delayMicroseconds(100); // tHOLD = 100us min.

  for (i=128; i >0 ; i >>= 1) {
		A2051_SCLK_L;
		A2051_SCLK_H;
		
		if(A2051_SDIO_Read == 1){//这个地方有可能出错 可能是0
			res |= i;
		}
//    digitalWrite (SCLK, LOW);
//    digitalWrite (SCLK, HIGH);
//    if( digitalRead (SDIO) == HIGH )
//      res |= i;
  }

  return res;
}

void writeRegister(byte address, byte data) {
	byte i=0;
  address |= 0x80; // MSB indicates write mode.
//  pinMode (SDIO, OUTPUT);

  for (i = 128; i > 0 ; i >>= 1) {
		A2051_SCLK_L;
		if((address & i) != 0){
			A2051_SDIO_H;
		}
		else{
			A2051_SDIO_L;
		}
		A2051_SCLK_H;
//    digitalWrite (SCLK, LOW);
//    digitalWrite (SDIO, (address & i) != 0 ? HIGH : LOW);
//    digitalWrite (SCLK, HIGH);
  }

  for (i = 128; i > 0 ; i >>= 1) {
		A2051_SCLK_L;
		if((data & i) != 0){
			A2051_SDIO_H;
		}
		else{
			A2051_SDIO_L;
		}
		A2051_SCLK_H;
//    digitalWrite (SCLK, LOW);
//    digitalWrite (SDIO, (data & i) != 0 ? HIGH : LOW);
//    digitalWrite (SCLK, HIGH);
  }

	delay_us(100);
//  delayMicroseconds(100); // tSWW, tSWR = 100us min.
}
