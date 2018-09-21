#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1SEL &= ~BIT0; //sets P1 select bits to 1
	P1SEL2 &= ~BIT0;
	P1DIR |= 0x01; //sets direction to output
	P1DIR |= 0x40; //sets direction to output
	unsigned int i = 0; //used as a counter
	while (1)
	{
	    P1OUT ^= 0x01; //sets the output to toggle led
	    if(i==0x03){ //checks to see if the counter gets to 3, then toggles the other led, and resets counter
	        P1OUT ^= 0x40; //toggles led
	        i=0;
	    }
	    i++; //increments counter
	    __delay_cycles(500000);

	}
	return 0;
}
