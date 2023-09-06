#include <iostream> 
using namespace std;

int main() {
	int random = rand() % 100;
	int num;
	cout << "Guess the number " << endl;
	while (1) {
		cin >> num;
		if (num > random) {
			if ( ((num % random) == 1) || ((num % random) == 2) || ((num % random) == 3)){
				cout << "High, Try again" << endl;
			}
			else
			{
				cout << "Too High, Try again" << endl;
				continue;
			}
		}
		else if (num < random) {
			if (((random % num) == 1) || ((random % num) == 2) || ((random % num) == 3)) {
				cout << "Low, Try again" << endl;
			}
			else {
				cout << "Too Low, Try again" << endl;
				continue;
			}
		}
		else if (num == random) {
			cout << "Correct!" << endl;
			break;
		}
	
	}
	
}