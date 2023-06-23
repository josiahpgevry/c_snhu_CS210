//Project three
//Date: 18JUN23
//Author: Josiah Gevry


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//Class for storeitems
class StoreItems
{
public: //public functions
	void DisplayMenu();
	void FindItem(string inputWord);
	ifstream file;
	void PrintList();
	void PrintDashes();
	void PrintHistogram();
	void FileCreation();
private: //private variables
	string tempItem;
	int stringCompared = -1;
	int itemCount = 0;
	vector <string> foundItems;
	vector <int> itemQuantity;
	
};

//used to print border during output

void StoreItems::PrintDashes() {
	cout << "------------------------------------" << endl;
}

//function for searching for items
void StoreItems::FindItem(string inputWord) {
	file.open("CS210_Project_Three_Input_File.txt");
	while (!file.eof()) {
		file >> tempItem;
		stringCompared = inputWord.compare(tempItem);
		if (stringCompared == 0) {
			itemCount += 1;
		}
	}
	file.close();
	foundItems.push_back(inputWord);
	itemQuantity.push_back(itemCount);
	cout << "" << endl;
	cout << inputWord << " was found " << itemCount << " times." << endl;
	cout << "" << endl;
	itemCount = 0;
}

//Menu funtion
void StoreItems::DisplayMenu() {
	cout << "Corner Grocer Menu:" << endl;
	cout << "Option 1: Search for Item" << endl;
	cout << "Option 2: Print search list" << endl;
	cout << "Option 3: Print search list histogram" << endl;
	cout << "Option 4: Exit the program" << endl;
	cout << "Please enter the number for the option you wish to see:" << endl;

}

//Used to print all searches and results
void StoreItems::PrintList() {
	int i = 0;
	PrintDashes();
	for (i = 0; i < foundItems.size(); ++i) {
		cout << foundItems[i] << " " << itemQuantity[i] << endl;
	}
	PrintDashes();
}

//Used to print all searches and results as histogram
void StoreItems::PrintHistogram() {
	int i = 0;
	int j = 0;
	PrintDashes();
	for (i = 0; i < foundItems.size(); ++i) {
		cout << foundItems[i] << " ";

		for (j = 0; j < itemQuantity[i]; ++j) {
			cout << "*";
		}
		cout << "" << endl;
	}
	PrintDashes();
}

//creates file with search results
void StoreItems::FileCreation() {
	int i = 0;
	ofstream file("frequency.dat");
	for (i = 0; i < foundItems.size(); ++i) {
		file << foundItems[i] << " " << itemQuantity[i] << endl;
	}
	file.close();

}







int main() {
	//variables + objects
	string userInputWord;
	int userInput = 0;
	StoreItems objectOne;

	//loop while user does not want to exit
	while (userInput != 4) {
		objectOne.DisplayMenu();
		cin >> userInput;

		//loop for input validation
		while (!cin) {
			cout << "Invalid input! Please enter an integer." << endl;
			cin.clear();
			cin.ignore(100, '\n');
			cin >> userInput;
		}
		
		//if-else statements for users desires
		if (userInput == 1) {
			userInput = 0;
			cin.clear();
			cout << "What item would you like to search for?" << endl;
			cin >> userInputWord;
			objectOne.FindItem(userInputWord);
		}
		else if (userInput == 2) {
			objectOne.PrintList();
			userInput = 0;
		}
		else if (userInput == 3) {
			objectOne.PrintHistogram();
			userInput = 0;
		}
		else if (userInput == 4) {
			cout << "You have selected to exit." << endl;
		}
		else {
			cout << "Invalid selection" << endl;
			cin.clear();
			userInput = 0;
		}
	}

	//exit message + file creation
	cout << "Ended application. Created data file." << endl;
	objectOne.FileCreation();



	return 0;
}
