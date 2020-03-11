#include<iostream>
#include<ctime>
#include<string>
using namespace std;
int balance = 0;

int  AddMoney(int *balance, int money, char ansver2) {
	cout << "Do you want to add money? " << "\n\n\t\t\"y\" or \"n\":" << endl;
	cin >> ansver2;
	if (ansver2 == 'y') {
		cout << "How much money you want to add? " << endl;
		int money = 0;
		cin >> money;
		*balance += money;
		cout << endl;
		cout << "Your balance: " << *balance << " USD" << endl;
	}
	else if (ansver2 == 'n') {
		cout << "Goodbye!" << endl;
	}
	return *balance;
}
int Prize(int *balance,string array[], int size, int doorChoice, int money, char ansver2, int kubik, int number) {

	cout << "Select a door: " << endl;
	cout << "(Think well - you have only one chance!)" << endl;
	cout << "-----   -----   -----   -----   -----   -----" << endl;
	cout << "|   |   |   |   |   |   |   |   |   |   |   |" << endl;
	cout << "| 1 |   | 2 |   | 3 |   | 4 |   | 5 |   | 6 |" << endl;
	cout << "|   |   |   |   |   |   |   |   |   |   |   |" << endl;
	cout << "-----   -----   -----   -----   -----   -----" << endl;
	cin >> doorChoice;
	string yourPrize = array[doorChoice - 1];
	cout << "Congratulations! Your prize: " << yourPrize << endl;
	if (doorChoice == 1) {
		*balance = *balance + 1;
	}
	else if (doorChoice == 2) {
		*balance = *balance + 1000000;
	}
	cout << "Your balance: " << *balance << endl;
	return *balance;
}
int Kubik(int *balance, int kubik, int number, string array[], int size, int doorChoice, int money, char ansver, char ansver2) {
	*balance = *balance - 200;
	srand(time(0));
	kubik = 1 + rand() % 15;
	cout << "Guess what number fell on the cube? (from 1 to 15): " << endl;
	cin >> number;
	if (number != kubik) {
		cout << "Sorry, you didn't guess((" << endl;
	}
	else if (number == kubik) {
		cout << "You guessed the number!" << endl;
		return Prize(balance,array, size, doorChoice, money, ansver2, kubik, number);
	}
	cout << "Your balance: " << *balance << endl;
	return *balance;

}
int Play(int *balance, int money, char ansver, int ansver2, int kubik, int number, string array[], int size, int doorChoice) {
	cout << "Do you want to play an exciting game? " << "\n\n\t\t\"y\" or \"n\":" << endl;
	cin >> ansver;
	if (ansver == 'n') {
		cout << "Goodbye!" << endl;
		return *balance;
	}
	else {
		if (*balance<200) {
			cout << "Please, add money to your account! - The price of one game - 200$ " << endl;
			cout << endl;
			cout << "Your balance: " << *balance << " USD" << endl;
			*balance = AddMoney(balance, money, ansver2);
			return Play(balance, money, ansver, ansver2, kubik, number, array, size, doorChoice);
		}
		else if (*balance >= 200) {
			kubik = Kubik(balance, kubik, number, array, size, doorChoice, money, ansver, ansver2);
			return Play(balance, money, ansver, ansver2, kubik, number, array, size, doorChoice);

		}
	}
	return Play(balance, money, ansver, ansver2, kubik, number, array, size, doorChoice);
}

int main() {
	int balance = 0;
	char ansver = 'y';
	char ansver2 = 'n';
	int money = 0;
	int kubik = 0;
	int number = 0;
	const int size = 6;
	int doorChoice = 0;
	string ArrPize[size] = { "1$","million$","villa","Chupa-Chups","bike","car" };

	Play(&balance, money, ansver, ansver2, kubik, number, ArrPize, size, doorChoice);

	system("pause");
	return 0;
}