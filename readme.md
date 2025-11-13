## Extra's
1. LCD name display: use PIC16f877a instead of pic16f84a, also change this microcontroller in the microC project settings 
2. Stepper motor: use an additional driver named: ULN2003A
3. use 74LS47 bcd to 7 segment decoder in Keypad 

## STM 32:
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