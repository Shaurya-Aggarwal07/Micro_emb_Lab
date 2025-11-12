void main() {  
    TRISB = 0x00;  // Set PORTB as output  
    PORTB = 0x00;  // Initialize PORTB  
    while(1) {  
        PORTB = 0b0001;  // For sequence 0001  
        Delay_ms(200); // Delay of 200 ms  
        PORTB = 0b0010;  // For sequence 0010  
        Delay_ms(200); // Delay of 200 ms  
        PORTB = 0b0100; // For sequence 0100  
        Delay_ms(200); // Delay of 200 ms  
        PORTB = 0b1000; // For sequence 1000  
        Delay_ms(200); // Delay of 200 ms  
    }  
}