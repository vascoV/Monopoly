#ifndef SQUARES_H
#define SQUARES_H
#include "Squares.h"
#endif
#include <string>

const char POUND = 156;

class CSpecialSquares : public CSquare
{
private:
	string name;
	int price = 0;
	int rent = 0;
	int type;
	CPlayer* owner;

public:
	CSpecialSquares(string _name, int _price, int _rent, int _type) : CSquare(_name, _type)
	{
		name = _name;
		price = _price;
		rent = _rent;
		type = _type;
		owner = nullptr;
	}

	void SetOwner(CPlayer* own)
	{
		owner = own;
	}

	//getters
	int GetType() //return the sqyare type
	{
		return type;
	}
	string GetName() //return the property name
	{
		return name;
	}
	int GetPrice() //return the property owner
	{
		return price;
	}
	int GetRent() //return the rent price of the property 
	{
		return rent;
	}
	CPlayer* GetOwner()
	{
		return owner;
	}

	void BonusCard(CPlayer* playerLand)
	{
		// using a switch for choosing a random  bonus card
		int ChooseBonusCard = Random(); 
		switch (ChooseBonusCard) {
		case 1:
			cout << "Find some money. " << "Player gains " << POUND << "20\n"; playerLand->addMoney(20);
			break;
		case 2:
			cout << "Win competition. " << " Player gains " << POUND << "50\n"; playerLand->addMoney(50);
			break;
		case 3:
			cout << "Tax rebate. " << " Player gains " << POUND << "100\n"; playerLand->addMoney(100);
			break;
		case 4:
			cout << "Win lottery. " << " Player gains " << POUND << "150\n"; playerLand->addMoney(150);
			break;
		case 5:
			cout << "Bequest. " << " Player gains " << POUND << "200\n"; playerLand->addMoney(200);
			break;
		case 6:
			cout << "Birthday. " << " Player gains " << POUND << "300\n"; playerLand->addMoney(300);
			break;
		default:
			cout << "NOT FOUND";
			break;
		}
		cout << playerLand->getName() << "  " << "Remaining Balance: " << POUND << playerLand->getMoney() << endl;
	}
	void PenalyCard(CPlayer* playerLand)
	{
		// using a switch for choosing a random  penalty card
		int ChoosePenaltyCard = Random();
		switch (ChoosePenaltyCard) {
		case 1:
			cout << "Pay food bill. " << " Player loses" << POUND << "20\n"; playerLand->reduceMoney(20);
			break;
		case 2:
			cout << "Pay phone bill. " << " Player loses " << POUND << "50\n"; playerLand->reduceMoney(50);
			break;
		case 3:
			cout << "Pay heating bill. " << " Player loses " << POUND << "100\n"; playerLand->reduceMoney(100);
			break;
		case 4:
			cout << "Pay vehicle tax. " << " Player loses " << POUND << "150\n"; playerLand->reduceMoney(150);
			break;
		case 5:
			cout << "Pay fuel bill. " << " Player loses " << POUND << "200\n"; playerLand->reduceMoney(200);
			break;
		case 6:
			cout << "Pay windfall tax. " << "Player loses " << POUND << "300\n"; playerLand->reduceMoney(300);
			break;
		default:
			cout << "NOT FOUND";
			break;
		}
		cout << playerLand->getName() << "  " << "Remaining Balance: " << POUND << playerLand->getMoney() << endl;
	}
	void GoToJail(CPlayer* playerLand, vector<CSquare*> board) 
	{
		int playerPosition = 6; //send the player to the Jail
		playerLand->SetPosition(playerPosition);
		cout << playerLand->getName() << "  " << "goes to " << board.at(playerPosition) << endl;
		playerLand->reduceMoney(50);
		cout << playerLand->getName() << "  " << "pays " << POUND << "50" << endl;
		cout << playerLand->getName() << "  " << "Remaining Balance: " << POUND << playerLand->getMoney() << endl;
	}
	void Jail(CPlayer* playerLand)
	{
		cout << playerLand->getName() << "  " << "is just visiting" << endl;
	}
	void FreeParking(CPlayer* playerLand)
	{
		cout << playerLand->getName() << "  " << "is resting" << endl;
	}
};
