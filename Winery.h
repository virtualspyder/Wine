#ifndef WINERY_H__
#define WINERY_H__

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>  // used for sort
#include <vector>
#include <cctype>
#include <ctime>

using namespace std;

class Winery
{
public:
//
// inplement and add functions
//
    Winery();
    Winery(string inputName, string inputAddr, string inputStreet,
		string inputCity, string inputState, string inputZip, string inputCountry);

    string getName();
    string getAddress();

private:
    int    id;
    string wineryName;
    string street, city, state, country;
    string addr, zip;
};

#endif // WINERY_H__