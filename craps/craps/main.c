#include "craps.h"

int main(void)
{
	int menu_option = 0, die1 = 0, die2 = 0, die3, sum = 0,
		first_roll = 0, add_or_subtract = 0, current_credits = 0, 
		bet_amount = 0, new_credits = 0;
	int* dice[2] = { 0 };
	char option = '\0';

	srand((unsigned int)time(NULL));
	/* Start Craps Main Menu */
	do
	{
		/* Main menu options for user */
		printf("Craps! Menu:\n\n");
		printf("Choose an option:\n");
		printf("1. Display game rules.\n");
		printf("2. Play!\n");
		printf("3. Credits\n");
		printf("4. Exit game.\n");
		scanf("%d", &menu_option);

		switch (menu_option)
		{

		/*1. Display game rules */
		case 1:
			print_game_rules();
			break;

		/* 2. Play Craps! */
		case 2:
			/* get initial bet */
			bet_amount = get_bet(current_credits);
			roll_dice(dice, 2); // roll dice
			sum = sum_dice(dice, 2); // get the sum of the two dices that were rolled
			/* Display First roll */
			putchar('\n');
			printf("Sum of roll: %d\n", sum);
			/* Determine by the first roll if player wins, loses, or continues to roll until
			   player makes his point */
			first_roll = is_win_loss_or_point(sum);

			if (first_roll == 1) // player automatically wins and if player bet, gets his win added
			{
				printf("You win, now give me some of that luck!!\n\n");
				add_or_subtract = 1;
			}

			else if (first_roll == 0) // player automatically loses and bet gets deducted
			{
				printf("You lost! Take a shower, maybe you can wash off that bad luck\n\n");
				add_or_subtract = 0;
			}

			else if (first_roll == -1) // player continues until player makes his point or rolls a 7 before making point
			{
				int option = 0;
				option = is_point_loss_or_neither(sum);
				if (option == 1)
				{
					printf("You win!\n\n");
					add_or_subtract = 1;

				}
				else if (option == 0)
				{
					printf("You lost!\n\n");
					add_or_subtract = 0;
				}
			} 
			current_credits = adjust_credit_balance(current_credits, bet_amount, add_or_subtract);
			printf("Current credits: %d\n\n", current_credits);
			break;

		case 3:	
			current_credits = get_credits();
			break;

		case 4:
			system("cls");
			printf("Goodbye human!\n");
			break;

		default:
			system("cls");
			printf("Invalid choice. Try again, human!\n");
			break;
		}
	} while (menu_option !=4);

	return 0;
}