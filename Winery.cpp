#include "Winery.h"

Winery::Winery(string inputName, string inputAddr, string inputStreet,
	string inputCity, string inputState, string inputZip, string inputCountry) : 
	wineryName(inputName), 
		street(inputStreet), 
		city(inputCity), 
		state(inputState), 
		zip(inputZip), 
		country(inputCountry)
	{}

string Winery::getName()
{
	return wineryName;
}

string Winery::getAddress()
{
	return addr;
}


