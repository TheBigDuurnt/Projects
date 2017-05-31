// PBCalculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;

// Functions (Defined at bottom)
int pbInput(int);
void mainMenu(int, int, int, int, int, int, int, int, int, int, int, int, int);
void failSafe();
int main() {
	// Base Stats
	int Str = 10, Dex = 10, Con = 10, Int = 10, Wis = 10, Cha = 10;
	// points that will calculate Point Buy
	int pbStr = 0, pbDex = 0, pbCon = 0, pbInt = 0, pbWis = 0, pbCha = 0;


	int choice;     // choice: input of stat change
	int temp;	    // temp: stores pbStr, pbDex, pbCon, pbInt, pbWis, pbCha
	char end = 'n';  // end: ends program
	int pointBuy;


	do {
		pointBuy = pbStr + pbDex + pbCon + pbInt + pbWis + pbCha; // TOTAL POINT BUY (keep here, so that pointBuy is updated)

																  //MAIN MENU OF PROGRAM
		mainMenu(pointBuy, pbStr, pbDex, pbCon, pbInt, pbWis, pbCha, Str, Dex, Wis, Con, Int, Cha);

		while (!(cin >> choice)) {
			{
				failSafe();
				mainMenu(pointBuy, pbStr, pbDex, pbCon, pbInt, pbWis, pbCha, Str, Dex, Wis, Con, Int, Cha); }
		}


		//Switch Statements that changes each stat (Str Dex Con etc...) and calls the pbInput function to change each pbStat (pbStr, pbDex, pbCon, etc...)
		switch (choice) {
		// Strength Option
		case 1: cout << "What would you like to change your Strength stat to? \nChoose a number between 7 and 18 [Current Str : " << Str << "]: ";
			while (!(cin >> temp)) {
				{
					failSafe();
					cout << "What would you like to change your Strength stat to? [Current Str : " << Str << "]: "; }
			}

			if ((temp > 6 && temp < 19)) {
				Str = temp;
				pbStr = pbInput(temp);
			}
			else {
				cout << "Invalid Input: Number was not between 7 & 18" << endl;
				system("pause");
			}
			break;
		// Dexterity Option
		case 2: cout << "What would you like to change your Dexterity stat to? [Current Dex : " << Dex << "]: ";
			while (!(cin >> temp)) {
				{
					failSafe();
					cout << "What would you like to change your Dexterity stat to? [Current Dex : " << Dex << "]: "; }
			}

			if ((temp > 6 && temp < 19)) {
				Dex = temp;
				pbDex = pbInput(temp);
			}
			else {
				cout << "Invalid Input: Number was not between 7 & 18" << endl;
				system("pause");
			}
			break;
		// Constitution Option
		case 3: cout << "What would you like to change your Constitution stat to? [Current Con : " << Con << "]: ";
			while (!(cin >> temp)) {
				{
					failSafe();
					cout << "What would you like to change your Constitution stat to? [Current Con : " << Con << "]: "; }
			}

			if ((temp > 6 && temp < 19)) {
				Con = temp;
				pbCon = pbInput(temp);
			}
			else {
				cout << "Invalid Input: Number was not between 7 & 18" << endl;
				system("pause");
			}
			break;
		// Constitution Option
		case 4: cout << "What would you like to change your Intelligence stat to? [Current Int : " << Int << "]: ";
			while (!(cin >> temp)) {
				{
					failSafe();
					cout << "What would you like to change your Intelligence stat to? [Current Int : " << Int << "]: "; }
			}

			if ((temp > 6 && temp < 19)) {
				Int = temp;
				pbInt = pbInput(temp);
			}
			else {
				cout << "Invalid Input: Number was not between 7 & 18" << endl;
				system("pause");
			}
			break;
		// Wisdom Option
		case 5: cout << "What would you like to change your Wisdom stat to? [Current Wis : " << Wis << "]: ";
			while (!(cin >> temp)) {
				{
					failSafe();
					cout << "What would you like to change your Wisdom stat to? [Current Wis : " << Wis << "]: "; }
			}

			if ((temp > 6 && temp < 19)) {
				Wis = temp;
				pbWis = pbInput(temp);
			}
			else {
				cout << "Invalid Input: Number was not between 7 & 18" << endl;
				system("pause");
			}
			break;
		// Charisma Option
		case 6: cout << "What would you like to change your Charisma stat to? [Current Cha : " << Cha << "]: ";
			while (!(cin >> temp)) {
				{
					failSafe();
					cout << "What would you like to change your Charisma stat to? [Current Cha : " << Cha << "]: "; }
			}

			if ((temp > 6 && temp < 19)) {
				Cha = temp;
				pbCha = pbInput(temp);
			}
			else {
				cout << "Invalid Input: Number was not between 7 & 18" << endl;
				system("pause");
			}
			break;


		case 7: // Choice to End Program
			do {
				cout << "End Program? (Y/N): ";
				cin >> end;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

			} while (!(end == 'y' || end == 'Y' || end == 'n' || end == 'N'));
			break;

		case 8: //Resets all Values back to base value
			Str = 10; Dex = 10; Con = 10; Int = 10; Wis = 10; Cha = 10;
			pbStr = 0; pbDex = 0; pbCon = 0; pbInt = 0; pbWis = 0; pbCha = 0;
			break;

		default: cout << "Invalid Option. Press enter for Main Menu" << endl;
			break;
		}

	} while (end == 'N' || end == 'n');
	return 0;
}
// Funtion changes the value of pbStr, pbDex, etc.. by returning the value for each point buy.

int pbInput(int temp)
{
	switch (temp) {
	case 7: return -4;
	case 8: return -2;
	case 9: return -1;
	case 10: return 0;
	case 11: return 1;
	case 12: return 2;
	case 13: return 3;
	case 14: return 5;
	case 15: return 7;
	case 16: return 10;
	case 17: return 13;
	case 18: return 17;
	}

}
// Main Menu of Program
void mainMenu(int pointBuy, int pbStr, int pbDex, int pbCon, int pbInt, int pbWis, int pbCha, int Str, int Dex, int Wis, int Con, int Int, int Cha) {

	pointBuy = pbStr + pbDex + pbCon + pbInt + pbWis + pbCha; // TOTAL POINT BUY (keep here, so that pointBuy is updated)

	system("CLS");
	cout << " Point Buy Calculator" << endl;
	cout << "-----------------------" << endl;
	cout << "1. Str | " << Str << " | " << pbStr << " points" << endl;
	cout << "-----------------------" << endl;
	cout << "2. Dex | " << Dex << " | " << pbDex << " points" << endl;
	cout << "-----------------------" << endl;
	cout << "3. Con | " << Con << " | " << pbCon << " points" << endl;
	cout << "-----------------------" << endl;
	cout << "4. Int | " << Int << " | " << pbInt << " points" << endl;
	cout << "-----------------------" << endl;
	cout << "5. Wis | " << Wis << " | " << pbWis << " points" << endl;
	cout << "-----------------------" << endl;
	cout << "6. Cha | " << Cha << " | " << pbCha << " points" << endl;
	cout << "-----------------------" << endl;
	cout << "Point Buy : " << pointBuy << endl;
	cout << "7. End Program" << endl;
	cout << "8. Reset Point Buy" << endl;

	cout << "\nEnter the number of the stat you wish to change: ";

}

//prevents users from abusing system, via typing in multiple characters
void failSafe()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	system("cls");
}

