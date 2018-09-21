#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	PM5CTL0 &= ~LOCKLPM5; //unlocks the gpio pins
	P1DIR |= BIT0; //sets direction to output
	P1DIR &= ~BIT1; //sets direction to input

	P1REN |= BIT1; //enables the pull up-down resistor
	P1OUT |= BIT1; //enables pull down resistor
	while(1){
	    if(P1IN & BIT1){ //button pressed inversely
	            P1OUT &= ~BIT0; //sets it to off when pressed 11111110
	    }else{
	            P1OUT |= BIT0; //sets to on when pressed
	    }

	}

	return 0;
}
