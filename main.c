#define F_CPU 16000000UL
#include<stdint.h>
#include<avr/io.h>
#include<util/delay.h>

//CONFIGURING THE PINS
void mcu_init(void)
{
    DDRB |= (1 << PORTB5);//configures LED_PIN as an input pin
    DDRB &= ~(1 << PORTB2);//configures BUTTON_PIN as an input pin
}

//TURNING LED ON AND OFF
void set_led_state(int state)
{
    if(state)
        PORTB |= (1 << PORTB5);
    else
        PORTB &= ~(1 << PORTB5);
}

//READING THE BUTTON_STATE
int read_button_state(void)
{
    if((PINB & (1 << PORTB2)) == 0)
        return 1;//True means a button pin is reading from  a non resistive path connected to GND
    else
        return 0;//False a button pin is reading through an external pull up resistor from the PORT register
                 // (Port Output Register) that has set the button pin bit high!
}



//The main function
int main(void)
{
    mcu_init();
    while (1)
    {
        int button_state = read_button_state();
        set_led_state(button_state);
        _delay_ms(10);
    }
    return 0;
}
