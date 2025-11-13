## Extra's
1. LCD name display: use PIC16f877a instead of pic16f84a, also change this microcontroller in the microC project settings 
2. Stepper motor: use an additional driver named: ULN2003A
3. use 74LS47 bcd to 7 segment decoder in Keypad 
---
## STM 32: (blink led)
NOTE- for any extra dialog box asking Y/N choose Y
1. launch it
2. file-->new stm project
3. board select --> (nucleo)f103-->select it & click next
4. type project name and create it in C
5. on the board, set PA5 to GPIO_Output
6. choose GPIO from system core and PA5 from the list in mid tab and add a user label and press Ctrl+S
7. Now in the code that appears, go to while(1) loop inside main function and write:
``` HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);```
8. Save the .c file
9. Go to project option in navbar & click build all 
10. Connect Nucleo board with PC & press run in IDE
11. Click OK in the Edit dialog box
12. Press reset button the board
---
## STM:32 (ADC)
- choose f401 nucleo board
- we will change config of A0 pin to ADC1_xx
- instead of step6 of above do this:
1. click on gear icon to build
2. go to line 102 and replace the while loop with this code:
```c
uint16_t adc_value;
char msg[10];

while (1)
{
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
    adc_value = HAL_ADC_GetValue(&hadc1);

    sprintf(msg, "%hu\r\n", adc_value);
    HAL_UART_Transmit(&huart2, (uint8_t *)msg, strlen(msg), HAL_MAX_DELAY);

    HAL_Delay(1000);
}

```
3. click on debug and then run pe click kro
4. STM ka kaam hogya
5. Open PuTTy
    - Choose serial
    - set speed to 115200
    - select com
    - ensure arduino is connected to pc
    - ensure potentiometer is connected to arduino as follows:
        - jaha se cylinder nikal raha hai usko apne face ki taraf karke
        - bich wali wire at A0
        - left wali wire at Vcc (5volt)
        - right wali at Gnd
    - select open
