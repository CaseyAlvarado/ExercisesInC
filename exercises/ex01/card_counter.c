/*
 * Program to calculate the number of cards in the shoe.
 * This code is released under the Vegas Public License.
 * (c)2014, The College Blackjack Team.
 */

#include <stdio.h>
#include <stdlib.h>

int interpretCards(char card[]){ 
/* Evaluates the card array of user input

Translates the higher face cards into a number. 
Translates numbers into themselves. 
Checks if the number is within the approrporate input range.
 */
	int val = 0; 
	switch(card[0]) {
		 case 'K':
		 case 'Q':
		 case 'J':
			 val = 10;
			 break;
		 case 'A':
			 val = 11;
			 break;
		 case 'X':
		 	val =  0; 
		 	break; 
		 default:
		 	val = atoi(card);
		 	if ((val < 1) || (val > 10)) {
			 puts("I dont understand that value!");
			 val = 0; 
			}
	 }
	 return val; 
}

int UpOrDown(int value){ 
/* Evaluates the value intput

Returns true if the value is between 2 and 7, and false otherwise. 
 */
	int val = 0; 
	if ((value > 2) && (value < 7))
	 	val = 1;
	 else if (value == 10) 
	 	val = 0;
	 return val; 
}

int main()
{
/* Prompts the user for input and puts the reply in the given buffer.

User input is truncated to the first two characters.

prompt: string prompt to display card_name: buffer where result is stored */
 char card_name[3];
 int count = 0;
 do {
 	int card_val = 0; 
	 puts("Enter the card_name: ");
	 scanf("%2s", card_name);
	 card_val = interpretCards(card_name); 
	 if (!card_val)
	 	continue; 
	 if(UpOrDown(card_val))
	 	count++; 
	 else
	 	count--;
	 printf("Current count: %i\n", count);

 } while (card_name[0] != 'X'); 
 return 0;
}
