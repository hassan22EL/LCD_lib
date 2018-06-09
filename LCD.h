

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _LCD_H
#define	_LCD_H
#define RS  RB0 
#define EN  RB1 
#define D4  RB2
#define D5  RB3
#define D6  RB4 
#define D7  RB5
/*
#define LCD LCD 
extern volatile unsigned short LCD @ 0x005;
typedef union {
    struct {
        unsigned RS : 1;
        unsigned EN : 1;
        unsigned RW : 1;
        unsigned D0 : 1;
        unsigned D1 : 1;
        unsigned D2 : 1;
        unsigned D3 : 1;
        unsigned D4 : 1;
        unsigned D5 : 1;
        unsigned D6 : 1;
        unsigned D7 : 1;
    };
}
LCDbits_t;
extern volatile LCDbits_t LCDbits@ 0x005;
#define TRISLCD TRISLCD
extern volatile unsigned short TRISLCD @ 0x008;
typedef union {
    struct {
        unsigned TRISR0 : 1;
        unsigned TRISEN : 1;
        unsigned TRISRW : 1;
        unsigned TRISD0 : 1;
        unsigned TRISD1 : 1;
        unsigned TRISD2 : 1;
        unsigned TRISD3 : 1;
        unsigned TRISD4 : 1;
        unsigned TRISD5 : 1;
        unsigned TRISD6 : 1;
        unsigned TRISD7 : 1;
    };
} TRISLCDbits_t;
extern volatile TRISLCDbits_t TRISLCDbits @ 0x008;
 */
void LCD_INIT();
void Data_PORT(char Data);
void LCD_Command(char Command);
void LCD_Write_Data(char Data);
void LCD_CLEAR();
void LCD_Set_cursor(char x, char y);
void LCD_Write_String(char *s);
void LCD_Shift_Right();
void LCD_Shift_left();
void LCD_Write_INT_NUMBER(int value);
void LCD_Write_Float_Number(float valu);
#endif	/*LCD_H */

