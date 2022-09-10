#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	srand(time(NULL));
	int level { 0 }, min_n { 1 }, max_n { 10 }, n { 0 }, guess { 0 },
			lives { 0 }, multiplier { 1 }, score { 0 };
	bool alive { 0 }, hint { 0 };

	cout << "Let's play \"Guess my number\"!" << endl;

	do {
		cout << "Choose your level" << endl;
		cout << "1 - Easy (from 1 to 10)" << endl;
		cout << "2 - Hard (from 10 to 100)" << endl;
		cout << "0 - Exit" << endl;
		cin >> level;
		switch (level) {
		case 1:
			min_n = 1;
			max_n = 10;
			break;
		case 2:
			min_n = 10;
			max_n = 100;
			break;
		case 0:
			return 0;
		default:
			cout << "Please enter 1, 2 or 0!" << endl;
		}
	} while (!level);

	cout << "Try to guess my number between " << min_n << " and " << max_n
			<< "!" << endl;
	lives = (min_n + max_n) / 2 / level;
	multiplier = level * 5;
	alive = (lives > 0);
	n = min_n + rand() % (max_n - min_n + 1);
	cout << "Rules of the game:" << endl;
	cout << "Every guess will cost you 1 life." << endl;
	cout << "If you guess wrong, you will be offered a hint." << endl;
	cout << "Taking the hint will also cost you 1 life." << endl;
	cout << endl;


	while (alive) {
		cout << "You are alive" << endl;
		cout << "You have " << lives << " lives left" << endl;
		cout << "Enter your guess" << endl;
		cin >> guess;
		if (guess == n) {
			break;
		} else {
			lives--;
			cout << "Wrong guess! Do you want a hint?" << endl;
			cout << "0 to refuse, anything else to take" << endl;
			cin >> hint;
			if (hint) {
				lives--;
				cout << "My number is " << ((n < guess) ? "lesser" : "greater")
						<< " than your guess" << endl;
			}
			cout << endl;
		}

		alive = (lives > 0);
	}

	if (alive) {
		cout << endl;
		score = lives * multiplier;
		cout << "Congratulations! You've guessed the number " << n
				<< " correctly" << endl;
		cout << "You've finished the game with " << lives
				<< " lives. Your final score is " << score << endl;
	} else {
		cout
				<< "Sorry, you're dead. You've run out of lives before guessing the number "
				<< n << endl;
	}

	return 0;
}
