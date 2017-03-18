#ifndef PLAYER_H
#define PLAYER_H
#include "Player.h"
#endif


class CSquare
{
private:
	string name;
	int type;
public:
	CSquare(string _name, int _type)
	{
		name = _name;
		type = _type;
	}

	virtual string GetName() = 0;
	virtual void SetOwner(CPlayer* owner) {}
	virtual int GetType() = 0;
	virtual int GetPrice() { return 0; } 
	virtual int GetRent() { return 0; } 
	virtual CPlayer* GetOwner(){return nullptr;}
	virtual int GetColourGroup() { return 0; } 
	virtual void BonusCard(CPlayer* playerLand) {}
	virtual void PenalyCard(CPlayer* playerLand) {}
	virtual void GoToJail(CPlayer* playerLand, vector<CSquare*> board) {}
	virtual void Jail(CPlayer* playerLand) {}
	virtual void FreeParking(CPlayer* playerLand) {}
};
