unsigned short kp = 0;
char keypadPort at PORTB;

void main(){
    TRISA = 0;
    PORTA = 0;

    Keypad_Init();
    
    while(1){
        
        do{
            kp = Keypad_Key_Press();
        }while(!kp);

        if(kp <= 3){
            PORTA = kp;
        }else if (kp > 3 && kp <= 7) {
            PORTA = kp - 1;
        }else if (kp > 8 && kp <= 11) {
            PORTA = kp - 2;
        }

    }
}