#include <mega32.h>
#include <delay.h>
// Alphanumeric LCD functions
#include <alcd.h>
#include <stdio.h>
#include <stdlib.h>
#define MIN PINA.0
#define HOUR PINA.1
// Declare your global variables here

void main(void)
{
char h=0,m=0,s =0;
char str[32];

//int i;

DDRA=0x00;
PORTA=0x03;
DDRB=0x00;
PORTB=0x00;
DDRC=0x00;
PORTC=0x00;
DDRD=0x00;
PORTD=0x00;


lcd_init(16*2);
lcd_gotoxy(5,0);
lcd_putsf("Reza Sabzi");
delay_ms(2000);
lcd_clear();

while (1)
      {
        s++;
        
        if(s>59){
            s = 0;
            m++;
            if(m > 59){
                m = 0;
                h++;
                if(h > 23){
                    h = 0;
                }
            }    
        }
        lcd_gotoxy(5,0);
        sprintf(str, "%02u:%02u:%02u", h,m,s);
        lcd_puts(str);
        if(MIN == 0){
            s = 0;
            m++;
            if(m > 59) m = 0;
            sprintf(str, "%02u:%02u:%02u", h,m,s);
            lcd_gotoxy(5,0);
            lcd_puts(str);
            delay_ms(200);
        }
        if(HOUR == 0){
            s = 0;
            h++;
            if(h > 23) h = 0;
            sprintf(str, "%02u:%02u:%02u", h,m,s);
            lcd_gotoxy(5,0);
            lcd_puts(str);
            delay_ms(200);
        }
        delay_ms(1000);
      }
      
}
