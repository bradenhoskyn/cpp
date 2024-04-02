#include <iostream>
using namespace std;

int main() {
	int firstNum;
	int secondNum;
	int total;

	cout << "what is your first number" << endl;
	cin << firstNum;

	cout << "Second Number?" << endl;
	cin << secondNum;	

	if (firstNum > secondNum) {
		total = firstNum += secondNum;
	} else if (firstNum < secondNum) {
		cout << "almost" << endl;
	

	return 0;
}
