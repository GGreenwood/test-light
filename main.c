#include <avr/io.h>
#include <util/delay.h>
#include "Neopixel.h"

#define PIN PB0
#define DELAY 4

#define GET_BIT(TGT, PIN) ((TGT) & (1 << (PIN))) 
#define SET_BIT(TGT, PIN)    do { TGT |=  (1 << (PIN)); } while(0)
#define CLEAR_BIT(TGT, PIN)  do { TGT &= ~(1 << (PIN)); } while(0)
#define TOGGLE_BIT(TGT, PIN) do { TGT ^=  (1 << (PIN)); } while(0)

int main(void)
{
    SET_BIT(DDRB, PIN);
    while(1) {
        for(uint8_t i = 255; i; i--) {
            showColor(255, 255 - i, 0, 8);
            _delay_ms(DELAY);
        }
        for(uint8_t i = 255; i; i--) {
            showColor(i, 255, 0, 8);
            _delay_ms(DELAY);
        }
        for(uint8_t i = 255; i; i--) {
            showColor(0, 255, 255 - i, 8);
            _delay_ms(DELAY);
        }
        for(uint8_t i = 255; i; i--) {
            showColor(0, i, 255, 8);
            _delay_ms(DELAY);
        }
        for(uint8_t i = 255; i; i--) {
            showColor(255 - i, 0, 255, 8);
            _delay_ms(DELAY);
        }
        for(uint8_t i = 255; i; i--) {
            showColor(255, 0, i, 8);
            _delay_ms(DELAY);
        }
    }
}
