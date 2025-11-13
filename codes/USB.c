void setup() {
  Serial.begin(9600);          // Start serial communication at 9600 baud

  Serial.println("USB Serial Communication Started!");
  Serial.println("Type something below:");
}

void loop() {
  // Check if data is available from the computer
  if (Serial.available() > 0) {
    char msg = Serial.read();  // Read one character
    Serial.print("You typed: ");
    Serial.println(msg);       // Send it back (echo)
  }
}
