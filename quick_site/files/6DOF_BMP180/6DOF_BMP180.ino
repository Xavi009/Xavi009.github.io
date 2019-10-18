//////6 DOF//////
#include <MPU6050_tockn.h>
#include <Wire.h>
MPU6050 mpu6050(Wire);                       //Name the MPU6050 module "mpu6050"


//////BMP180//////
#include <Adafruit_BMP085.h>
Adafruit_BMP085 bmp;
double currentAirPressure = 100865;          //Current air pressure of the location. VERY IMPORTANT
                                             //Set to pressure in Kenosha 4/25/19
                                             //10m=120Pa difference


//=================================================================================//
void setup() {
  Serial.begin(9600);
  // BMP180 Initialization //
  //Serial.println("REBOOT");
  bmp.begin();

  // 6 DOF Initialization //
  Wire.begin();
  mpu6050.begin();                   //Initialize MPU6050
  //mpu6050.calcGyroOffsets(true);     //Initialize gyroscope calibration
}


//=================================================================================//
void loop() {
  printData();
  delay(10);
}

void printData() {
  mpu6050.update();
  Serial.print(" Acceleration (g)  X: "); Serial.print(mpu6050.getAccX());  //Print acceleration values in G-force
  Serial.print("\t");
  Serial.print(" Y: "); Serial.print(mpu6050.getAccY());
  Serial.print("\t");
  Serial.print(" Z: "); Serial.print(mpu6050.getAccZ());                                         
  Serial.print("\t");
  Serial.print("  Gyro (rad)  X: "); Serial.print(mpu6050.getGyroX());                           //Print gyroscope values in rad/s
  Serial.print("\t");
  Serial.print(" Y: "); Serial.print(mpu6050.getGyroY());                                        
  Serial.print("\t");
  Serial.print(" Z: "); Serial.print(mpu6050.getGyroZ());                                        
  Serial.print("\t");
  Serial.print("  Temp (C)="); Serial.print(bmp.readTemperature());                              //Print temperature values in Celsius
  Serial.print("\t");
  Serial.print("  Pressure (Pa)="); Serial.print(bmp.readPressure());                            //Print pressure values in Pascal
  Serial.print("\t");
  Serial.print("  Altitude (m)="); Serial.print(bmp.readAltitude(currentAirPressure));           //Print altitude values in Meters
  Serial.print("\t");
  Serial.print("  Time (ms)="); Serial.println(millis());                                         //Print time values in Milliseconds
}                                                                                                
