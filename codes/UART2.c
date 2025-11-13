// MASTER
// Transmitter Arduino (sends bitstream of length 5-9)
void setup() {
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  // Send a few example binary sequences (between 5–9 bits)
  // Let's say we send: 10101 (5 bits), 1100110 (7 bits), etc.

  byte bitSequences[] = {
    B10101,     // 5 bits: 10101
    B1001101,   // 7 bits: 1001101
    
  };
  
  byte lengths[] = {5, 7};  // Bit lengths of above

  for (int s = 0; s < 2; s++) {
    byte data = bitSequences[s];
    byte len = lengths[s];

    // Send the length first, so receiver knows how many bits to expect
    Serial.write(len);     // Send data length
    Serial.write(data);    // Send raw data
    delay(1000);           // Wait before next
  }

  delay(5000); // Wait 5 seconds and repeat
}

//-----------------------------------------------------------------------------------

//SLAVE
// Receiver Arduino with UART frame simulation and Serial Plotter output
void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println("Start\tBit0\tBit1\tBit2\tBit3\tBit4\tBit5\tBit6\tBit7\tParity\tStop");
}

void loop() {
  if (Serial.available() >= 2) {
    byte len = Serial.read();     // First byte = number of bits (5–9)
    byte data = Serial.read();    // Second byte = data bits

    // Extract data bits into array
    byte bits[9] = {0};
    for (byte i = 0; i < len; i++) {
      bits[i] = (data >> i) & 0x01;
    }

    // --- UART Frame Construction ---
    byte startBit = 0;
    byte stopBit = 1;

    // Calculate even parity
    byte parity = 0;
    for (byte i = 0; i < len; i++) {
      parity ^= bits[i];  // XOR to find parity
    }

    // --- Serial Monitor Output ---
    Serial.print("UART Frame: ");
    Serial.print(startBit);
    Serial.print(" ");

    for (byte i = 0; i < len; i++) {
      Serial.print(bits[i]);
      Serial.print(" ");
    }

    Serial.print(parity);
    Serial.print(" ");
    Serial.print(stopBit);
    Serial.println();

    // --- Serial Plotter Output ---
    Serial.print(startBit);
    Serial.print('\t');

    for (byte i = 0; i < 8; i++) {  // Max bits shown is 8 for plot stability
      if (i < len)
        Serial.print(bits[i]);
      else
        Serial.print(0); // Fill empty slots with 0
      Serial.print('\t');
    }

    Serial.print(parity);
    Serial.print('\t');
    Serial.print(stopBit);
    Serial.println();
  }
}

