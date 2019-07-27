/*
 Use the below template for our wine lab project.
 
 The lab instruction is embeeded in the program.

 You need to read  the winery file name and store the wineary information.

 You need then read the wine information, and store the wine information, and link (assign)
 winery information for the wine.

 You Program needs to:

       	1. Display all the wine has a score (valid inputs is between 0 and 100) 
	between x and y.  For example, if user enters range between 98 and 100, 
	also display the total number of wine between the selected range and 
	average price for the selected wines.

	2. Display  all the wine has a price between x and y, and after print 
	out all the wine in the selected range, also print out the total number 
	of wine between the selected range and average price for the selected wines.

 	3. Display  all the wines sorted by price (you can use c++ vector sort 
	function i discussed in class and look at example here 
	http://www.cplusplus.com/articles/NhA0RXSz/ 

	4. Display  all the wines sorted by score (you can use c++ vector sort 
	function http://www.cplusplus.com/articles/NhA0RXSz/
 
	5. Display all the wine of a wine type (ask user to enter wine type and then 
   	search wine type and print out all wines of this wine type, also print out the 
	total number of wine of this wine type and average price for the selected wines.

    */
 
#include "Wine.h"

using namespace std;

bool sortPrice(Wine *wine1, Wine *wine2);
bool sortScore(Wine *wine1, Wine *wine2);
string toLowerString(string s);

void printMeFirst()
{
    cout << "Program written by: " << "Hamza Sheikh" << endl;
    cout << "Course info: " << "Lab2" << endl << "CS-116: Thursday class" << endl << endl;
    time_t now = time(0);

    char* t= ctime(&now);
    cout << "Date: " << t << endl;
}

int main()
{
	int i;
    vector<Wine*> wineList;
    vector<Winery*> wineryList;
	
	printMeFirst();
	
    //
    // implement your programs
    //
	
	string fileName("winery.txt");
   	string fileName2("winelist.txt"); 

	ifstream inFile(fileName.c_str());
	ifstream inFile2(fileName2.c_str());

	while(!inFile.is_open())
	{
		cout << "The file \"" << fileName << "\" cannot be found. Enter another file : "; 
		getline(cin, fileName); inFile.clear(); inFile.open(fileName.c_str());
	}

	cout << "The file \"" << fileName << "\" has been opened successfully." << endl << endl; 

	while(!inFile2.is_open())
	{
		cout << "The file \"" << fileName2 << "\" cannot be found. Enter another file : "; 
		getline(cin, fileName2); inFile2.clear(); inFile2.open(fileName2.c_str());
	}

	cout << "The file \"" << fileName2 << "\" has been opened successfully." << endl << endl; 

    // Read winery file information contains winery information and store them

    /*
	winery.txt file format:
	
	WineryName; street; city; state; country
	
	For example:
   		Stags;6150 Silverado Trl;Napa;CA; USA

	WineryName: 	Stags
	street:		6150 Silverado Trl
	city:		Napa
	state:		CA
	country:	USA
    */

	string newLine;
	string wineryName, street, city, state, country;

	while(inFile)
	{
		if(getline(inFile, wineryName, ';'))
		if(getline(inFile, street, ';'))
		if(getline(inFile, city, ';'))
		if(getline(inFile, state, ';'))
		if(getline(inFile, country))
		{
			// Winery(string inputName, string inputAddr, string inputStreet,
            // string inputCity, string inputState, string inputZip, string inputCountry);
			wineryList.push_back(new Winery(wineryName, "No information", street, city, state, "No ZIP information", country));
			getline(inFile, newLine);
		}
	}

    /*
      Read wine file contains wine information, and assign winery information
      to the wine information
      Store everything in vector pointer of wine
      winelist.txt format:
 
	wineName ; wineType; wineVintage; wineScore; winePrice; wineryName

      Each field is separated by ;
      For example:

	Stags Leap Artemis Cabernet;Red;2013,92,65,Stags

	wineName:  	Stags Leap Artemis Cabernet
	wineType:  	Red
	wineVintage:	2013
	wineScore:	92
	winePrice:	65
	wineryName:	Stags

  */

	stringstream ss;
	string wineName, wineType, wineVintage, wineScore, winePrice;
	int vintage, score;
	double price;

	while(inFile2)
	{
		if(getline(inFile2, wineName, ';'))
		if(getline(inFile2, wineType, ';'))
		if(getline(inFile2, wineVintage, ';'))
		if(getline(inFile2, wineScore, ';'))
		if(getline(inFile2, winePrice, ';'))
		if(getline(inFile2, wineryName))
		{

			for(i = 0; i < wineryName.size(); i++)
			{
				if(!isalpha(wineryName[i]) && wineryName[i] != ' ')
				{
					wineryName.erase(wineryName.begin() + i); i--;
				}
			}

			ss << wineVintage; ss >> vintage;

			ss.str("");
			ss.clear();

			ss << wineScore; ss >> score;

			ss.str("");
			ss.clear();

			ss << winePrice; ss >> price;

			getline(inFile2, newLine);
			Winery * winery = NULL;
			for(vector<Winery*>::iterator it = wineryList.begin(); it != wineryList.end(); ++it)
			{
				if((*it)->getName() == wineryName) { winery = *it; break; }
			}

			if(winery == NULL)
			{
				cout << "Reading error : Winery name not match!!!" << endl;
				cout << "Please press any key to continue. . . "; cin.get(); exit(100);
			}

		    wineList.push_back(new Wine(wineName, wineType, vintage, score, price, winery));
		}
	}

	int x, y;
	do
	{
		cout << "Enter x and y (between 0 and 100) : " << endl;
		if(cin >> x >> y && x >= 0 && y >= 0 && x <= 100 && y <= 100)
		{
			// Ensure that (x <= y)
			if(x >= y)
			{
				int temp = x;
				x = y;
				y = temp;
			}
		}
		else
		{
			x = -1;
			if(!cin)
			{
				cin.clear();
				cin.ignore(1000, '\n');
			}
			cout << "You have enter an invalid value. Please try again\n\n";
		}
	} while(x == -1);

    //  After you have read the infomration/data from the files, then you need to
    //  implement function to do the following :

	/*
   		1. Display all the wine has a score (valid inputs is between 0 and 100) 
		between x and y. For example, if user enters range between 98 and 100, 
		also display the total number of wine between the selected range and average price for the selected wines.
	*/

	int nFound = 0;
	double totalPrice = 0;
	cout << "1. Wines which have a score between " << x << " and " << y << " : " << endl;
	{
			for(vector<Wine*>::iterator it = wineList.begin(); it != wineList.end(); ++it)
			{
				if((*it)->getScore() >= x && (*it)->getScore() <= y)
				{
					nFound++;
					totalPrice += (*it)->getPrice();
					(*it)->print();
					cout << endl;
				}
			}	
	}

	cout << "Found " << nFound << " wine(s) with a score between " << x << " and " << y << endl;  
	if(nFound > 0)
	{
		cout << "+ The total price of all selected wines : $" << totalPrice << endl;
		cout << "+ The average price for all selected wines : $" << totalPrice / double(nFound) << endl;
	}

	cout << endl;
    
	/*
		2. Display all the wine has a price between x and y, and after print 
		out all the wine in the selected range, also print out the total number 
		of wine between the selected range and average price for the selected wines.
	*/

	nFound = 0;
	totalPrice = 0;
	cout << "2. Wines which have a price between " << x << " and " << y << " : " << endl;
	{
			for(vector<Wine*>::iterator it = wineList.begin(); it != wineList.end(); ++it)
			{
				if((*it)->getPrice() >= x && (*it)->getPrice() <= y)
				{
					nFound++;
					totalPrice += (*it)->getPrice();
					(*it)->print();
					cout << endl;
				}
			}	
	}
	cout << "Found " << nFound << " wine(s) with a price between " << x << " and " << y << endl;  
	if(nFound > 0)
	{
		cout << "+ The average price for all selected wines : $" << totalPrice / double(nFound) << endl;
	}

	cout << endl;

    /*  
	 	3. Display all the wines sorted by price (you can use c++ vector sort 
		function i discussed in class and look at example here 
		http://www.cplusplus.com/articles/NhA0RXSz/ 
	*/
	cout << "3. Display all the wines sorted by price : " << endl;
	sort(wineList.begin(), wineList.end(), sortPrice);
	for(i = 0; i < (int)wineList.size(); i++)
	{
		wineList[i]->print(); cout << endl;
	}

    /*  
		4. Display  all the wines sorted by score (you can use c++ vector sort 
		function http://www.cplusplus.com/articles/NhA0RXSz/
	*/

	cout << "4. Display all the wines sorted by score : " << endl;
	sort(wineList.begin(), wineList.end(), sortScore);
	for(i = 0; i < (int)wineList.size(); i++)
	{
		wineList[i]->print(); cout << endl;
	}

    /*  
		5. Display all the wine of a wine type (ask user to enter wine type and then 
   		search wine type and print out all wines of this wine type, also print out the 
		total number of wine of this wine type and average price for the selected wines.
    */

	do
	{
		cout << "Please enter Wine type (Red or White) : "; cin >> wineType;
		wineType = toLowerString(wineType);
		if(wineType != "red" && wineType != "white")
		{
			wineType = "Unknown";
		}
	} while(wineType == "Unknown");


 	nFound = 0;
	totalPrice = 0;
	cout << "5. Display all the wines that are '" << wineType << "' wines : " << endl;
	{
			for(vector<Wine*>::iterator it = wineList.begin(); it != wineList.end(); ++it)
			{
				if(toLowerString((*it)->getType()) == wineType)
				{
					nFound++;
					totalPrice += (*it)->getPrice();
					(*it)->print();
					cout << endl;
				}
			}	
	}
	cout << "Found " << nFound << " wine(s) which are '" << wineType << "' wines." << endl;
	if(nFound > 0)
	{
		cout << "+ The average price for all selected wines : $" << totalPrice / double(nFound) << endl;
	}

	cout << endl;
 
	for(i = 0; i < (int)wineList.size(); i++) delete wineList[i];
	for(i = 0; i < (int)wineryList.size(); i++) delete wineryList[i];

	cout << "Thank you for using the program." << endl; 
	cout << "Please press any key to continue. . . "; cin.get();
	return 0;
}


bool sortPrice(Wine *wine1, Wine *wine2)
{
	return(wine1->getPrice() < wine2->getPrice());
}

bool sortScore(Wine *wine1, Wine *wine2)
{
	return(wine1->getScore() < wine2->getScore());
}

string toLowerString(string s)
{
	int i;
	for(i = 0; i < (int)s.length(); i++) s[i] = tolower(s[i]);
	return s;
}