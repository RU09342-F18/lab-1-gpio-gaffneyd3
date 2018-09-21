#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	PM5CTL0 &= ~LOCKLPM5; //unlocks the gpio pins
	P1DIR |= BIT0; //sets direction
	P2DIR |= BIT0;
	unsigned int count = 0;
	while(1){
	    P2OUT ^= BIT0; //toggles led2
	    __delay_cycles(500000); //delays so we can see the led blink
	    if(count == 3){ //TOGGLES
	        P1OUT ^= BIT0; //toggles led1
	        count = 0;
	    }

	    count ++;



	}
	return 0;
}
