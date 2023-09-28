#include <iostream>
using namespace std;
int digit, row, coloumn;
char token = 'X';
char col[3][3]{ {' ',' ',' '}, {' ',' ',' '} , {' ',' ',' '} };
string player1;
string player2;

void printboard() {
	cout << "    |    |    \n";
	cout << " " << col[0][0] << "  " << "|";
	cout << " " << col[0][1] << "  " << "|";
	cout << " " << col[0][2] << "  " << endl;
	cout << "----|----|---- \n";
	cout << " " << col[1][0] << "  " << "|";
	cout << " " << col[1][1] << "  " << "|";
	cout << " " << col[1][2] << "  " << endl;
	cout << "----|----|---- \n";
	cout << " " << col[2][0] << "  " << "|";
	cout << " " << col[2][1] << "  " << "|";
	cout << " " << col[2][2] << "  " << endl;
	cout << "    |    |    \n";
}


bool checkwinner() {
	for (int i = 0; i < 3; i++) {
		if ((col[i][0] == col[i][1] && col[i][0] == col[i][2] && col[i][0] != ' ') ||
			(col[0][i] == col[1][i] && col[0][i] == col[2][i] && col[0][i] != ' ')) {
			return true;
		}
	}

	if ((col[0][0] == col[1][1] && col[0][0] == col[2][2] && col[0][0] != ' ') ||
		(col[2][0] == col[1][1] && col[2][0] == col[0][2] && col[2][0] != ' ')) {
		return true;
	}

	return false;
}

int main()
{
	cout << "Enter the name of the first player:\n";
	cin >> player1;
	cout << "Enter the name of the second player:\n";
	cin >> player2;
	cout << player1 << " will play as 'X', And ";
	cout << player2 << " will play as 'O' \n";

	while (checkwinner() != true) {
		for (int i = 0; i < 9; i++) {
			cout << "Current board :\n";
			printboard();

			if (token == 'X') {
				cout << player1 << " Choose a place\n";
				cin >> digit;
			}
			else if (token == 'O') {
				cout << player2 << " Choose a place\n";
				cin >> digit;
			}
			if (digit < 1 || digit > 9) {
				cout << "Invalid place, Try again\n";
				i--; //to make sure the same player chooses another place
				continue;
			}
			else if (digit >= 1 && digit <= 9) {
				if (digit == 1) {
					row = 0;
					coloumn = 0;
				}
				else if (digit == 2) {
					row = 0;
					coloumn = 1;
				}
				else if (digit == 3) {
					row = 0;
					coloumn = 2;
				}
				else if (digit == 4) {
					row = 1;
					coloumn = 0;
				}
				else if (digit == 5) {
					row = 1;
					coloumn = 1;
				}
				else if (digit == 6) {
					row = 1;
					coloumn = 2;
				}
				else if (digit == 7) {
					row = 2;
					coloumn = 0;
				}
				else if (digit == 8) {
					row = 2;
					coloumn = 1;
				}
				else if (digit == 9) {
					row = 2;
					coloumn = 2;
				}
			}

			if (col[row][coloumn] != ' ') {
				cout << "This place is taken, Choose another \n";
				i--;
				continue;
			}
			col[row][coloumn] = token;
			if (checkwinner()) {
				cout << " Current board \n";
				printboard();
				if (token == 'X') {
					cout << player1 << " wins";
				}
				else {
					cout << player2 << " wins";
				}
				break; // to end the game if anyone wins

			}

			if (token == 'X') {
				token = 'O';
			}
			else {
				token = 'X';
			}
		}
			    

			if (!checkwinner()) {
				cout << "No winner, it's a draw";
			}

		
	}
}