#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	PM5CTL0 &= ~LOCKLPM5; //unlocks the gpio pins
	P1DIR |= BIT0; //sets direction
	while(1){
	    P1OUT ^= BIT0; //toggles led
	    __delay_cycles(1000000); //delays so we can see the led blink
	}
	return (0);
}
