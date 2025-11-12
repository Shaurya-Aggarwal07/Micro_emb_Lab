// Define LCD Control Pins on PORTC 
#define rs PORTC.F0 
#define rw PORTC.F1 
#define en PORTC.F2 

unsigned int j; 
unsigned int i; 

void delay_custom(); 
void lcd_init(); 

void cmd(unsigned char a);
void dat(unsigned char b);
void show(unsigned char *s);

void main() {
  TRISB = 0x00;      // PORTB as output (LCD data)
  TRISC.F0 = 0;      // RS
  TRISC.F1 = 0;      // RW
  TRISC.F2 = 0;      // EN
  
  lcd_init();
  
  cmd(0x8A);  // Force cursor to 0x8A
  
  show("I LOVE IITP");

  while(1) {
    Delay_ms(250);   // Delay approx 250ms
    cmd(0x18);       // Shift display left
    Delay_ms(250);
  }
}

void delay_custom() {
    for(j = 0; j < 1000; j++);
}

void lcd_init() {
    cmd(0x38);  // Function set: 8-bit, 2 line, 5x8 font
    cmd(0x0C);  // Display ON, cursor OFF
    cmd(0x06);  // Entry mode set: increment
    cmd(0x80);  // Set DDRAM to 0x00 (home position)
}

void cmd(unsigned char a) {
    PORTB = a;
    rs = 0;
    rw = 0;
    en = 1;
    delay_custom();
    en = 0;
}

void dat(unsigned char b) {
    PORTB = b;
    rs = 1;
    rw = 0;
    en = 1;
    delay_custom();
    en = 0;
}

void show(unsigned char *s) {
    while(*s) {
        dat(*s++);
    }
}