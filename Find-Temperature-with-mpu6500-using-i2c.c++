#include <Arduino.h>
#include <Wire.h>

void setup()
{
  Wire.begin();
  Serial.begin(9600);
}

void loop()
{
  Wire.beginTransmission(0x68);
  Wire.write(0x41);
  Wire.endTransmission();
  Wire.requestFrom(0x68, 8);
  int TempH = Wire.read();
  
  Wire.beginTransmission(0x68);
  Wire.write(0x42);
  Wire.endTransmission();
  Wire.requestFrom(0x68, 8);
  int TempL =Wire.read();
  
  int temp_val = (TempH << 8) | TempL ;
  int temp = ((temp_val - 0 ) / 337 ) + 21 ;
  Serial.print("Room Temperature: ");
  Serial.println(temp);
  delay(1000);
}

