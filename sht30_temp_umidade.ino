#include <Wire.h>
#include "ClosedCube_SHT31D.h"

ClosedCube_SHT31D sht3xd;
SHT31D_RegisterStatus sr_sht30;
SHT31D temp_rh;

void setup()
{
	Wire.begin();

	Serial.begin(9600);
	Serial.println("ClosedCube SHT3X-D Who I Am Example");
	Serial.println("supports SHT30-D, SHT31-D and SHT35-D");

	sht3xd.begin(0x44); // I2C address: 0x44 or 0x45
}

void loop()
{
	// Serial.print("Serial #");
	// Serial.println(sht3xd.readSerialNumber());
  // sr_sht30 = sht3xd.readStatusRegister();
  // Serial.println(sr_sht30.rawData);   
  temp_rh = sht3xd.readTempAndHumidity(SHT3XD_REPEATABILITY_MEDIUM, SHT3XD_MODE_POLLING, 250);
  Serial.print(temp_rh.t); Serial.print(";"); Serial.println(temp_rh.rh);
  delay(500);
}
