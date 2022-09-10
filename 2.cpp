#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int d6(unsigned int seed) {
	srand(seed);
	const int dice_min { 1 }, dice_max { 6 };
	int roll = dice_min + rand() % (dice_max + 1 - dice_min);
	return roll;
}

int main() {
	const int rolls { 3 };
	int player_sum { 0 }, comp_sum { 0 };
	cout << "Let's play some dice!" << endl;
	cout << "We'll roll two d6 " << rolls
			<< " times and see who gets a larger total!" << endl;
	cout << "Press Enter";
	getchar();
	cout << endl;
	for (int i = 0; i < rolls; i++) {
		cout << "Roll " << i + 1 << " of " << rolls << endl;
		int roll = d6(time(NULL) + i + 1);
		comp_sum += roll;
		cout << "Computer rolls " << roll;
		roll = d6(time(NULL) + i + 2);
		comp_sum += roll;
		cout << ", " << roll << endl;
		cout << "Press Enter to roll!";
		getchar();
		roll = d6(time(NULL) + i + 3);
		player_sum += roll;
		cout << "You roll " << roll;
		roll = d6(time(NULL) + i + 4);
		player_sum += roll;
		cout << ", " << roll << endl;
		cout << endl;
		cout << "Your sum: " << player_sum << endl;
		cout << "Computer's sum: " << comp_sum << endl;
		cout << endl;
	}

	cout << "Game over!" << endl;
	cout << "Your total sum is " << player_sum << ", computer's total sum is "
			<< comp_sum << endl;
	(player_sum > comp_sum) ? cout << "You won!" : cout << "You lost!";
	cout << endl;

	return 0;
}
