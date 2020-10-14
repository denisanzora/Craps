#include "craps.h"

/* Diplsay game rules */
void print_game_rules(void)
{
	system("cls");
	printf("Rules:\n1. A Player rolls two dice.\n");
	printf("2. The sum of the two upward faces are calculated.\n");
	printf("3. If the sum is 7 or 11 on the first throw, the player wins!\n");
	printf("4. If the sum is 2, 3 or 12 on the first throw, the player loses and the house wins. \n");
	printf("5. If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's point.\n");
	printf("6. To WIN, you must continue rolling the dice until you make your point!\n");
	printf("7. The player loses by rolling a 7 BEFORE making the point.\n\n");
	printf("Example:\nIf your 1st roll = 7, you automatically WIN!\nBUT, if you roll 2 on first roll, you LOSE!\n");
	printf("Now, if you roll 5, you must roll again until you roll 5. BUT, if you roll a 7 BEFORE the point 5, then you LOSE!\n\n");
	printf("Bets:\nA player has the option to place a bet before the first roll. This is optional.\n\n");
}

/* Get the credits from the player and display message depending how many credits were added
   if credits >= 50, then players gets a funny positive message, anything else, a funny 
   negative comment.
   Return player's new credits. */
int get_credits(void)
{
	int* credits = 0;
	system("cls");
	printf("Credits: %d\n\n", credits);
	printf("1 credit = 1 BTC and so on...\nTry 50 >");
	scanf("%d", &credits);
	system("cls");
	printf("+%d credits were added.\n", credits);
	printf("Credits: %d\n\n\n", credits);
	if (credits >= 50)
	{
		printf("WOW! OKAAAY, wannabe baller >.>\n");
		printf("Press 2 to play, good luck and have fun!\n\n");
	}
	else
		printf("I know you got more money...\nBut, whatever.\nPress 2 to play...\n\n");
	return credits;
}
/* Get the bet before the player gets to roll, if yes, then ask much the player
   wants to bet. If player says yes to bet and has no funds, display message, else, display message
   Return player's bet*/
int get_bet(int credits)
{	
	char bet_y_n = '\0';
	int bet_amount = 0;
	system("cls");
	printf("Would you like to bet? (y or n) ");
	scanf(" %c", &bet_y_n);
	bet_y_n = tolower(bet_y_n); 
	if (bet_y_n == 'y')
	{
		printf("What would you like to bet?\n");
		scanf("%d", &bet_amount);

		if (bet_amount > credits)
		{
			putchar('\n');
			printf("Please go to credits under menu and add credits.\n");
			printf("No bet was placed.\n");
			printf("Note: player can only place a bet if there are enough funds.\n\n");
			bet_amount = 0;
		}
	}
	else if (bet_y_n == 'n')
	{
		printf("LOSER!\n\n");
	}
	return bet_amount;
}
/* Roll a dice 1 - 6. 
   No return, can call anytime roll_dice(dice, 2) in main */
void roll_dice(int dice[], int size)
{
	for (int index = 0; index < size; ++index)
	{
		dice[index] = rand() % 6 + 1;
	}
}
/* Sum the 2 dice that were rolled. 
   Return sum */
int sum_dice(int dice[], int size)
{
	int index = 0, sum = 0;

	while (index < size)
	{
		sum += dice[index];
		++index;
	}
	return sum;
}
/* Determine by the first roll if player automatically wins (7 or 11) returns 1,
   automatically loses (2, 3, 12) return 0, or gets assigned a point returns -1. */
int is_win_loss_or_point(int sum)
{
	if (sum == 7 || sum == 11)
	{
		return 1;
	}
	else if (sum == 2 || sum == 3 || sum == 12)
	{
		return 0;
	}
	else
		return -1;
}
/* Determine if current player's point is met before rolling a 7.
*  Returns 1 if the sum of the roll equals the player's current point. (WIN)
*  Return 0 if player rolls a 7 before matching point. (LOST)
	*/
int is_point_loss_or_neither (int point_value)
{
	int* dice[2] = { 0 };
	char option = '\0';
	int sum = 0;
	printf("Your new point is %d\n", point_value);
	do
	{
			system("pause");
			roll_dice(dice, 2);
			sum = sum_dice(dice, 2);
			printf("Sum of roll: %d\n", sum);
			if (sum == point_value)
			{
				return 1;
			}
	} while (sum != 7);
	return 0;
}
/*if player bet, then credits will be added if player won or credits will be
  deducted if player lost. 
  Returns the new total of credits */
int adjust_credit_balance(double credits, double wager_amount, int add_or_subtract)
{
	if (add_or_subtract == 1)
	{
		credits += wager_amount;
	}
	else if (add_or_subtract == 0)
	{
		credits -= wager_amount;
	}
	return credits;
}
