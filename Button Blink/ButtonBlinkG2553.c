#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1SEL &= ~0x09;
	P1SEL2 &= ~0x09;

	P1DIR |= BIT0; //sets direction of p1.0 to output
	P1DIR &= ~BIT3; //sets direction of P1.3 to input
	P1REN |= BIT3; //enables the pull up-down resistor
	P1OUT |= BIT3; //sets the pull down resistor
	while(1){
	    if(P1IN & BIT3)
	        P1OUT &= 0xFE; //sets output to 00000001 when pressed 11111110
	    else
	        P1OUT |= BIT0; //sets it to off when not pressed



	}
	return 0;
}
