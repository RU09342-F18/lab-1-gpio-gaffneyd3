#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1SEL &= ~BIT0; //set select bits to be 0
	P1SEL2 &= ~BIT0;
	P1DIR |= BIT0; //set direction to be output
	while(1){
	    P1OUT ^= BIT0; //toggle led from on to off
	    __delay_cycles(1000000); //delay so that we can see the led blink
	}
	return (0); //needs default return for method
}
