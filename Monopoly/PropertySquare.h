#ifndef SQUARES_H
#define SQUARES_H
#include "Squares.h"
#endif

class CProperties : public CSquare
{
private:
	string PropertyName;
	CPlayer* owner;
	int type;
	int Price;
	int Rent;
	int ColourGroup;

public:
	CProperties(string _PropertyName, int _price, int _type, int _rent, int _colourGroup) :CSquare(_PropertyName, _type)
	{
		PropertyName = _PropertyName;
		type = _type;
		Price = _price;
		Rent = _rent;
		ColourGroup = _colourGroup;
		owner = nullptr;
	}

	//setters
	void SetOwner(CPlayer* own) //set the property owner
	{
		owner = own;
	}

	//getters
	int GetType() //return the sqyare type
	{
		return type;
	}
	int GetColourGroup() //return the colour group number
	{
		return ColourGroup;
	}
	string GetName() //return the property name
	{
		return PropertyName;
	}
	int GetPrice() //return the property price
	{
		return Price;
	}
	int GetRent() //return the rent price of the property 
	{
		return Rent;
	}
	CPlayer* GetOwner() //retirn the owner
	{
		return owner;
	}

};
