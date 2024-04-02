#include <cstdlib>
#include <iostream>
#include "searchUtils.h"

/* Global constants */
const int NUM_ENTRIES = 15;

/**
 * This function performs a binary search, looking for 
 * searchTerm in list. 'list' must be sorted.
 * @param list - the *sorted* list to search
 * @param searchTerm - the number to look for
 * @return true iff searchTerm is found in list, false if not.
 */
bool binarySearch(const List<int> &list, const int searchTerm){
	int mid, guess;
	int count = list.size();
	mid = count/2;
	list.retrieve(mid, guess);
	if (guess == searchTerm) return true;
	if (searchTerm < guess) {
		mid = mid - 1;
		mid = mid/2;
		list.retrieve(mid, guess);
		if (guess == searchTerm) return true;
	} else if (searchTerm > guess) {
		mid = mid + 1;
		mid = (mid + count)/2;
		list.retrieve (mid, guess);
		if (guess == searchTerm) return true;
	}
	return false;
}

/**
 * This function performs a sequential search, looking for 
 * searchTerm in list. 
 * @param list - the list to search
 * @param searchTerm - the number to look for
 * @return true iff searchTerm is found in list, false if not.
 */
bool sequentialSearch(const List<int> &list, const int searchTerm){
	int size = list.size();
	for (int i = 0; i < size; i++) {
		int data;	
		list.retrieve(i, data);
		if(data == searchTerm) return true;
	}		
	
	return false;
}

/**
 * Insert NUM_ENTRIES ints into list, making sure the
 * entries are in sorted (increasing) order
 * @param list - The list to populate with an increasingly sorted list
*/
void loadSortedList(List<int> &list){
	srand(time(NULL));
	
	int num = 0;
	for (int i = 0; i < NUM_ENTRIES; i++) {
		num += rand() % 10;
		list.insert(i, num);
	}
}

/**
 * Insert NUM_ENTRIES ints into list, making sure they
 * entries are in random-esque order.
 * @param list - The list to populate with a random list
*/
void loadRandomList(List<int> &list){
	srand(time(NULL));
	
	int num = 0;
	for (int i = 0; i < NUM_ENTRIES; i++) {
		num = rand() % 100;
		list.insert(i, num);
	}
}

