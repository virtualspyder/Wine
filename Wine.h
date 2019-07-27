#ifndef WINE_H__
#define WINE_H__

#include "Winery.h"

using namespace std;

class Wine
{
public:
//
//  add any functions that you need for the program
//
	Wine(string inputName, string inputType, int inputVintage, int inputScore, double inputPrice, Winery *inputOrigin);

    void setWineName(string inputName);
    void setWineVintage(int inputVintage);

    string getName();
    string getType();
    int getVintage();
    int getScore();
    double getPrice();
    string getWineryName();
    void print();

private:
    string name;
    string type;
    int vintage;
    int score;  // wine rating
    double price;

    Winery *wineryOrigin;
};


#endif // WINE_H__