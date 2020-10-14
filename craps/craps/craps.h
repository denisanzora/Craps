/*
	Programmer: Denis Anzora
	Class: CptS 121; Lab Section 0
	Programming Assignment 4: Craps! Game

	Date: 10/12/2020

	Description: This program will first display the
				 main menu for the game Craps! in which
				 the user has the option to choose from:
				 1. Display Game Rules
				 2. Play the game craps!
				 3. Add credits if player has none to bet
				 4. Exit the game.

	Refer to "rules.txt" if you don't understand the rules
	of the game.

*/
#ifndef CRAPS_H
#define CRAPS_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // rand(), srand()
#include <time.h>	// time ()
#include <ctype.h> // putchar()

void print_game_rules(void);

int get_new_credits(void);

int get_credits(void);

int get_bet(int credits);

void roll_dice(int dice[], int size);

int sum_dice(int dice[], int size);

int is_win_loss_or_point(int sum);

int is_point_loss_or_neither(int point_value);

int adjust_credit_balance(double bank_balance, double wager_amount, int add_or_subtract);


#endif // !CRAPS_H
