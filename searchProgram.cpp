/**
 * Braden Hoskyn
 * 10/11/2021
 * This is a menu that prints and tests a sequential and binary search.
 */
#include <iostream>
#include <iomanip>
#include "searchUtils.h"
using namespace std;

/* Prototypes */
void print(int &);
void printMenu();
int getUserSearchValue();
int getUserMenuChoice();

int main(){
	//create a list that holds ints
	List<int> myList;

	do {

		printMenu();
		choice = getUserMenuChoice();

		if (choice == 1) {
			int searchVal;
			cout << "Enter a search value: ";
			cin >> searchVal;

			loadRandomList(myList);

			if (sequentialSearch(myList, searchVal)) {
				cout << "Your value is in the list!" << endl;
			} else { 
				cout << "Your value is not in the list" << endl;
			}
		} else if (choice == 2) {
			// binary search 
			// idk how to call this
		}

		//this prints out the list for verification:
		cout << "Your list:" << endl;
		myList.traverse(print);
		cout << endl;

	} while (choice != 3);

	return 0;
}

/**
 * Prints a menu from which the user can choose an option
 */
void printMenu(){
	cout << "********************************" << endl;
	cout << "* 1. Test Sequential search    *" << endl;
	cout << "* 2. Test Binary search        *" << endl;
	cout << "* 3. Exit                      *" << endl;
	cout << "********************************" << endl;
}

/**
 * Get the user's menu choice, making sure it's valid
 * before returning it
 * @return a value between 1-3
 */
int getUserMenuChoice(){
	int choice;
	cout << "Enter your menu choice (1-3): ";
	cin >> choice;

	while(choice < 1 || choice > 3){
		cout << "Wrong. Try again." << endl;
		cout << "Enter your menu choice (1-3): ";
		cin >> choice;
	}

	return choice;
}

/**
 * Get the user's search term, which should be a 
 * value >= 0
 * @return a value >= 0
 */
int getUserSearchValue(){
	int searchValue;
	cout << "Enter your search value(>= 0): ";
	cin >> searchValue;

	while(searchValue < 0){
		cout << "Wrong. Try again." << endl;
		cout << "Enter your search value (>= 0): ";
		cin >> searchValue;
	}

	return searchValue;
}

/**
 * This function can be used by a List's traverse() method
 * to print out each item in a List on the same line,
 * separated by spaces.
 * @param x - an item in the List. Passed by .traverse()
 */
void print(int &x){
	cout << setfill('0') << setw(2) << x << "  ";
}
