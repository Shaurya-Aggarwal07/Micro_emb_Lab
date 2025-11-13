// MASTER
#include <Wire.h>

void setup() {
  Serial.begin(9600);

  Wire.begin(); // Join I2C bus as master  
  delay(1000); 
}

void loop() {
  Wire.beginTransmission(8); // Address of slave
  Wire.write("Hello from Master");
  Wire.endTransmission();

  Serial.println("Sent to Slave: Hello from Master");

  delay(1000); 
}

//---------------------------------------------------------
// SLAVE
#include <Wire.h>

void setup(){
    Serial.begin(9600);

    Wire.begin(8);        // Set I2C slave address to 8
    Wire.onReceive(fn);
}

void loop() {
 
}

void fn(int bytes) {
    
  while (Wire.available()) {
    char c = Wire.read();
    Serial.print(c);
  }

  Serial.println();
}