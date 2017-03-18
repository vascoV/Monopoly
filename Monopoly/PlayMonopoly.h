#pragma once
#include <iostream>
#include <vector>
#include "PropertySquare.h"
#include "Random.h"
#include "SpecialSquare.h"

#define ALLSQUARES 26

using namespace std;

void MonopolyPlay(CPlayer* currentPlayer, vector<CSquare*> board, int dicenum) //function for how to play the monopoly game
{
	cout << currentPlayer->getName() << "  " << "rolled: " << dicenum << endl; 	//Display the current player and the dice number
	currentPlayer->MovePosition(dicenum); //Move player depend on the dice roll

	if (currentPlayer->GetPosition() > 25) // check if the player land or passed pver go
	{
		currentPlayer->SetPassedGo(true);
		currentPlayer->ResetPosition();
	}

	int playerPosition = currentPlayer->GetPosition(); // get the current position of the player
	cout << currentPlayer->getName() << "  " << "Lands on  " << board.at(playerPosition)->GetName() << endl; //get the player name and the square name that the payer landed on


	if (board.at(playerPosition)->GetType() == 1) //if statement to check if the player step on a property square
	{
		bool GroupOwner = true;
		int colourGroup = board.at(playerPosition)->GetColourGroup();

		if (currentPlayer->getMoney() > 0 && board.at(playerPosition)->GetOwner() == nullptr) //check if the porperty has owner or not
		{
			currentPlayer->reduceMoney(board.at(playerPosition)->GetPrice());
			board.at(playerPosition)->SetOwner(currentPlayer);
			cout << currentPlayer->getName() << "  " << "buys " << board.at(playerPosition)->GetName() << "  " << "for " << POUND << board.at(playerPosition)->GetPrice() << endl;
			cout << currentPlayer->getName() << "  " << "Remaining Balance: " << POUND << currentPlayer->getMoney() << endl;
			//cout << board.at(playerPosition)->GetColourGroup() << endl;
		}
		//if the palyer has negative balance can not buy any proprty
		else if (currentPlayer->getMoney() <= 0 && board.at(playerPosition)->GetOwner() == nullptr) {
			cout << "No one owns " << board.at(playerPosition)->GetName() << " but you don't have money to buy it" << endl;
		}
		else if (currentPlayer->getName() == board.at(playerPosition)->GetOwner()->getName()) //check if any of the players own this property
		{
			cout << currentPlayer->getName() << "  " << "already own this porperty " << endl;
		}
		else //check if the player own all the colour group 
		{
			for (int i = 0; i < ALLSQUARES; i++)
			{
				if (board.at(i)->GetColourGroup() == colourGroup)
				{
					if (board.at(i)->GetOwner() == nullptr)
					{
						GroupOwner = false;
					}
				}
			}
			if (GroupOwner == true) // if the owner has all the colour double the rent of the property
			{
				currentPlayer->reduceMoney(board.at(playerPosition)->GetRent());
				cout << currentPlayer->getName() << "  " << "pays " << POUND << 2 * (board.at(playerPosition)->GetRent()) << "  of goods " << endl;
				cout << currentPlayer->getName() << "  " << "Remaining Balance: " << POUND << currentPlayer->getMoney() << endl;
				board.at(currentPlayer->GetPosition())->GetOwner()->addMoney(board.at(playerPosition)->GetRent());//pay the rend to the another player
			}
			else //otherwise pay a single rent
			{
				currentPlayer->reduceMoney(board.at(playerPosition)->GetRent());
				cout << currentPlayer->getName() << "  " << "pays " << POUND << board.at(playerPosition)->GetRent() << "  of goods " << endl;
				cout << currentPlayer->getName() << "  " << "Remaining Balance: " << POUND << currentPlayer->getMoney() << endl;
				board.at(currentPlayer->GetPosition())->GetOwner()->addMoney(board.at(playerPosition)->GetRent());//pay the rend to the another player
			}
		}
	}
	if (currentPlayer->PassedGo() == true) // chech if the player passed the GO square
	{
		if (board.at(currentPlayer->GetPosition())->GetType() == 2)
		{
			cout << currentPlayer->getName() << "  " << "Lands on GO and Receive " << POUND << "200" << endl;
		}
		else
		{
			cout << currentPlayer->getName() << "  " << "Passed over GO and Receive " << POUND << "200" << endl;
		}
		currentPlayer->SetPassedGo(false);
	}
	else if (board.at(playerPosition)->GetType() == 3) //check if the player is on one of the airport squares
	{
		if (currentPlayer->getMoney() > 0 && board.at(playerPosition)->GetOwner() == nullptr) //check if the airported is owned to any of the players
		{
			currentPlayer->reduceMoney(board.at(playerPosition)->GetPrice());
			board.at(playerPosition)->SetOwner(currentPlayer);
			cout << currentPlayer->getName() << "  " << "buys " << board.at(playerPosition)->GetName() << "  " << "for " << POUND << board.at(playerPosition)->GetPrice() << endl;
			cout << currentPlayer->getName() << "  " << "Remaining Balance: " << POUND << currentPlayer->getMoney() << endl;
		}
		//if the palyer has negative balance can not buy any property
		else if (currentPlayer->getMoney() <= 0 && board.at(playerPosition)->GetOwner() == nullptr) {
			cout << "No one owns " << board.at(playerPosition)->GetName() << " but you don't have money to buy it" << endl;
		}
		else if (currentPlayer->getName() == board.at(playerPosition)->GetOwner()->getName()) //check if any of the players own this property
		{
			cout << currentPlayer->getName() << "  " << "already own this porperty " << endl;
		}
		else //paying the rent if the anther player already own the airport that the current player step on
		{
			currentPlayer->reduceMoney(board.at(playerPosition)->GetRent());
			cout << currentPlayer->getName() << "  " << "pays " << POUND << board.at(playerPosition)->GetRent() << "  of goods " << endl;
			currentPlayer->reduceMoney(10);
			cout << currentPlayer->getName() << "  " << "Remaining Balance: " << POUND << currentPlayer->getMoney() << endl;
			board.at(currentPlayer->GetPosition())->GetOwner()->addMoney(board.at(playerPosition)->GetRent());
		}

	}
	else if (board.at(playerPosition)->GetType() == 4) //player is choosing a Bonus Card
	{
		board.at(currentPlayer->GetPosition())->BonusCard(currentPlayer);
	}
	else if (board.at(playerPosition)->GetType() == 5) //player is choosing a Penalty Card
	{
		board.at(currentPlayer->GetPosition())->PenalyCard(currentPlayer);
	}
	else if (board.at(playerPosition)->GetType() == 6) //player is just visiting the Jail
	{
		board.at(currentPlayer->GetPosition())->Jail(currentPlayer);
	}
	else if (board.at(playerPosition)->GetType() == 7) //player Go To the Jail
	{
		board.at(currentPlayer->GetPosition())->GoToJail(currentPlayer, board);
	}
	else if (board.at(playerPosition)->GetType() == 8) //Player laneded on free parking square
	{
		board.at(currentPlayer->GetPosition())->FreeParking(currentPlayer);
	}
}
