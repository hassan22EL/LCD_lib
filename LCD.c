/*
 * File:   LCd.c
 * Author: Hassan
 *
 * Created on February 7, 2018, 2:13 PM
 */


#include <xc.h>
#include <string.h>
#include	<stdlib.h>
#include "LCD.h"
#define _XTAL_FREQ 8000000

void Data_PORT(char Data) {
    D4 = (Data >> 0)&0x01; //selected first bit
    D5 = (Data >> 1)&0x01; //selected sec bit
    D6 = (Data >> 2)&0x01; //selected third bit
    D7 = (Data >> 3)&0x01; //selected fourth bit
}

void LCD_Command(char Command) {
    char U, L; //U:Upper bits and L Lower bits 
    RS = 0; // Write Command  Though D4 To D7 
    U = Command & 0xF0; // select upper  bits 
    L = Command & 0x0F; // Select Lower bits
    Data_PORT(U >> 4); // Write Upper bits into D4 To D7 
    EN = 1; // Enable High TO Low (Write operation)
    __delay_ms(5); // loop instruction En=1 20
    EN = 0; // Enable Low 
    Data_PORT(L); // Write Lower bits into D0 To D3 
    EN = 1; // Enable High TO Low (Write operation)
    __delay_ms(5); // loop instruction En=1 
    EN = 0; // Enable Low 


}

void LCD_INIT() {

    LCD_Command(0x33); // function  set 8bit mode interface width=8bit and 5*8 dot format and 2 line on
    LCD_Command(0x32); // function set 8bit mode again interface width=8bit and 5*8 dot format and 2 line on
    LCD_Command(0x28); // function set 4bit mode (interface width=4bit and 5*8 dot format and 2 line on) 
    LCD_Command(0x0C); // Display on and  cursor oFF and blink off
    LCD_Command(0x06); // Address counter (AC) Automatic increment and no shift

}

void LCD_Write_Data(char Data) {
    char U, L; //U:Upper bits and L Lower bits 
RS = 1; // Write Data Though D4 To D7 
    U = Data & 0xF0; // select upper  bits 
    L = Data & 0x0F; // Select Lower bits
    Data_PORT(U >> 4); // Write Upper bits into D4 To D7 
  EN = 1; // Enable High TO Low (Write operation)
    __delay_us(20); // loop instruction En=1 20
    EN = 0; // Enable Low 
    Data_PORT(L); // Write Lower bits into D0 To D3 
    EN = 1; // Enable High TO Low (Write operation)  ````
    __delay_us(20); // loop instruction En=1 20
   EN = 0; // Enable Low 



}

void LCD_CLEAR() {
    LCD_Command(0x01); // this command clear display because D0=1 and D2 To D7 equal zero
}

void LCD_Set_cursor(char x, char y) {
    char position; // POsitin char 
    if (x == 1) {
        position = 0x80 + y - 1;
        LCD_Command(position); // write the command into LCD selected address cursor
        /*  x = number of line 
         * at y=0 the the cursor at first colum  and start
         *  address DDRAM =00H and End address 27H First line 
         * and B7=1 selected DDRAM address into LCD 0xC0 sum of operation
         * this low 0x80 +y-1 find the position of Cursor in first line 
         */

    } else if (x == 2) {
        position = 0xC0 + y - 1;
        LCD_Command(position); // write the command into LCD selected address cursor
        /* x = number of line 
         *  at y=0 the the cursor at first colum  and start
         *  address DDRAM =40H and End address 67H sec line 
         * and B7=1 selected DDRAM address into LCD  0xC0 sum of operation
         * this low 0xC0 +y-1 find the position of Cursor in sec line 
         */


    }
}

void LCD_Write_String(char *s) {
    /*identifier pointer working counter address into RAM MUC 
     * each char its address the pointer point the current address
     * such as Hassan the s pointer each address char
     * and method LCD write char take the char into LCD 
     
     */
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        LCD_Write_Data(s[i]);
    }
}

/* shifted display and cursor 
 * B3 B2       sate
 * 0  0    cursor shift left
 * 0  1    cursor shift right
 * 1  0    cursor and display shifted left
 * 1  1    cursor and display shifted right
 */
void LCD_Shift_Right() {

    LCD_Command(0x1C); //    cursor and display shifted right
}

void LCD_Shift_left() {
    LCD_Comman89d(0x18); //cursor and display shifted Left
}

void LCD_Write_INT_NUMBER(int value) {
    // Convert integer number to String 
    unsigned char buffer[8]; // buffer size 8 bit
    LCD_Write_String(itoa(buffer, value, 10));

}

void LCD_Write_Float_Number(float valu) {
    char *buf;
    int status;
    buf = ftoa(valu, &status);
    LCD_Write_String(buf);

}