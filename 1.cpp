#include <iostream>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::milliseconds
/*
 * Using C++11 std::this_thread::sleep_for function to stay OS-agnostic,
 * not because there's more than one thread
 */

using namespace std;

int main() {
	const int length { 25 };
	char symbol { 0 };
	bool vert { 0 };
	int menu { 0 }, delay { 0 };

	while (!menu) {
		cout << "Enter a symbol with which to draw the line: ";
		cin >> symbol;
		if (symbol)
			menu = true;
		else
			cout << "Wrong symbol!";
	}
	menu = false;
	while (!menu) {
		cout << "Draw it vertically or horizontally?" << endl;
		cout << "1 - Vertically" << endl;
		cout << "2 - Horizontally" << endl;
		cout << "3 - Exit" << endl;
		cin >> menu;
		switch (menu) {
		case 1:
			vert = true;
			break;
		case 2:
			vert = false;
			break;
		case 3:
			return 0;
		default:
			menu = false;
			cout << "Please enter 1, 2 or 3!" << endl << endl;
		}
	}
	menu = false;
	while (!menu) {
		cout << "Enter the desired speed" << endl;
		cout << "1 - Very fast" << endl;
		cout << "2 - Fast" << endl;
		cout << "3 - Medium" << endl;
		cout << "4 - Slow" << endl;
		cout << "5 - Exit" << endl;
		cin >> menu;
		switch (menu) {
		case 1:
			delay = 0;
			break;
		case 2:
			delay = 100;
			break;
		case 3:
			delay = 500;
			break;
		case 4:
			delay = 1000;
			break;
		case 5:
			return 0;
		default:
			menu = false;
			cout << "Please enter a number from 1 to 5!" << endl << endl;
		}
	}
	for (int i = 0; i < length; i++) {
		cout << symbol;
		if (vert)
			cout << endl;
		else
			cout << flush; // Need to always flush for realtime output
		this_thread::sleep_for(chrono::milliseconds(delay));
	}

	return 0;
}
