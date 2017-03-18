#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>
#include "Dice.h"
#include "PlayMonopoly.h"
#endif

using namespace std;

#define ROUNDS 20

string  squareName(string  name1, string  name2) // output a strin with space between the words
{
	string name;
	name = name1 + " " + name2; 
	return name;
}

string  jailName(string  name1, string  name2, string name3) // output a strin with space between the words
{
	string jailName;
	jailName = name1 + " " + name2 + " " + name3;
	return jailName;
}

int main()
{
	cout << endl << endl;
	cout << "\t\t\t\t\t\t\t" << "WELCOME TO MONOPOLY" << endl;
	cout << endl << endl;

	//Variables for the squares information
	string propertyName;
	string propertyName1;
	string propertyName2;
	int price;
	int rent;
	int colourGroup;
	int code;
	int line = 0;

	vector<CSquare*> board;

	ifstream monopolyFile; //read the monopoly file
	string wholeLine;
	monopolyFile.open("Monopoly.txt");

	//Creating CPlayers
	CPlayer* DOG = new CPlayer("DOG");
	CPlayer* CAR = new CPlayer("CAR");
	//initilize the start players position
	DOG->SetPosition(0); 
	CAR->SetPosition(0);

	// creating dice object
	CDice dice; 
	

	do {  //full the vector with the squares and read the file line by line
		if (line == 0 || line == 3 || line == 6 || line == 16) //read 2 items per line  (GO, BONUS, JAIL, Penalty)
		{
			monopolyFile >> code >> propertyName;
			board.push_back(new CSpecialSquares(propertyName, 0, 0, code));

		}
		else if (line == 9 || line == 23) //read 3 items per line (AIRPORTS )
		{
			monopolyFile >> code >> propertyName >> propertyName1;
			board.push_back(new CSpecialSquares(squareName(propertyName, propertyName1), 200, 10, code));
		}
		else if (line == 13) // FREE PARKING
		{
			monopolyFile >> code >> propertyName >> propertyName1;
			board.push_back(new CSpecialSquares(squareName(propertyName, propertyName1), 0, 0, code));
		}
		else if (line == 19)  //(GO TO JAIL)
		{
			monopolyFile >> code >> propertyName >> propertyName1 >> propertyName2;
			board.push_back(new CSpecialSquares(jailName(propertyName, propertyName1, propertyName2), 0, 0, code));
		}
		else  //(ALL PROPERTIES)
		{
			monopolyFile >> code >> propertyName >> propertyName1 >> price >> rent >> colourGroup;
			board.push_back(new CProperties(squareName(propertyName, propertyName1), price, code, rent, colourGroup));
		}
		line++;
	} while (getline(monopolyFile, wholeLine));
	
	monopolyFile.close();
	

	for (int i = 0; i < ROUNDS; i++)
	{
		cout << "*-----------Round " << i + 1 << "-----------*" << endl;
		cout << "-------------------------------" << endl;
		MonopolyPlay(DOG, board, dice.roll());
		cout << endl;
		MonopolyPlay(CAR, board, dice.roll());
		cout << endl;
		cout << endl;
	}
	
	system("pause");
}