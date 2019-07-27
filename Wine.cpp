#include "Wine.h"

Wine::Wine(string inputName, string inputType, int inputVintage, int inputScore, double inputPrice, Winery *inputOrigin) : 
	name(inputName), 
	type(inputType),
	vintage(inputVintage),
	score(inputScore),
	price(inputPrice),
	wineryOrigin(inputOrigin)
	{
	}

string Wine::getName()
{
	return name;
}

string Wine::getType()
{
	return type;
}

int Wine::getVintage()
{
	return vintage;
}

int Wine::getScore()
{
	return score;
}

double Wine::getPrice()
{
	return price;
}

string Wine::getWineryName()
{
	return wineryOrigin->getName();
}

void Wine::print()
{
	cout << "Name : " << getName() << endl;
	cout << "- Type : " << getType() << endl;
	cout << "- Vintage : " << getVintage() << endl;
	cout << "- Score : " << getScore() << endl;
	cout << "- Price : $" << getPrice() << endl;
	cout << "- Winery name : " << getWineryName() << endl;
}