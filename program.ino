#include <Arduino_LSM6DSOX.h>


float Ax, Ay, Az;
float Gx, Gy, Gz;

void setup()
{
    Serial.begin(9600);
    Serial.println("Nano RP2040 Connect is alive!");
    delay(1000);

    if(!IMU.begin()){
        Serial.println("Failed to init IMU");
        while(1);
    }
    
    Serial.print("Accelerometer sample rate = ");
    Serial.print(IMU.accelerationSampleRate());
    Serial.print("Hz");
    Serial.println();

    Serial.print("Gyroscope sample rate = ");
    Serial.print(IMU.gyroscopeSampleRate());
    Serial.print("Hz");
    Serial.println();
}

void loop() 
{
    if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(Ax, Ay, Az);
    Serial.println("Accelerometer data:");
    Serial.print(Ax); Serial.print('\t');
    Serial.print(Ay); Serial.print('\t');
    Serial.println(Az);
    Serial.println();
  }

  if (IMU.gyroscopeAvailable()) {
    IMU.readGyroscope(Gx, Gy, Gz);
    Serial.println("Gyroscope data:");
    Serial.print(Gx); Serial.print('\t');
    Serial.print(Gy); Serial.print('\t');
    Serial.println(Gz);
    Serial.println();
  }

  delay(500);
}