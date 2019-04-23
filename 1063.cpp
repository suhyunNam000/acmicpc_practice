#include <iostream>
#include <string>
using namespace std;
//킹
//https://www.acmicpc.net/problem/1063
int chess_panel[8][8];	//A:0 B:1 C:2 ... H:7
int king[2]; //[0]:ABC [1]:123
int stone[2]; //[0]:ABC [1]:123
string input_king, input_stone, this_move;

bool is_valid(int temp_row, int temp_col) {
	bool v_row = false;
	bool v_col = false;
	if ((temp_row >= 0) && (temp_row < 8)) v_row = true;
	if ((temp_col >= 0) && (temp_col < 8)) v_col = true;
	
	if (v_row && v_col) return true;
	else return false;
}

void moving(int row, int col) {
	if (is_valid(king[0] + row, king[1] + col)) {
		if ((king[0] + row == stone[0]) && (king[1] + col == stone[1])) {
			if (is_valid(stone[0] + row, stone[1] + col)) {
				stone[0] += row;
				stone[1] += col;
			}
			else return;
		}
		king[0] =king[0]+ row;
		king[1] =king[1]+ col;

		return;
	}
	else return;
}

void move_to(string command) {
	if (command == "R") { moving(1, 0); }
	else if (command == "L") {	moving(-1, 0);	}
	else if (command == "B") {	moving(0, -1);	}
	else if (command == "T") {	moving(0, 1);	}
	else if (command == "RT") { moving(1, 1);	}
	else if (command == "LT") { moving(-1, 1);	}
	else if (command == "RB") { moving(1, -1);	}
	else if (command == "LB") { moving(-1, -1);	}
}

int main() {
	int move; //=N
	cin >> input_king;
	cin >> input_stone;
	cin >> move;

	king[0] = input_king.at(0) - 'A';
	king[1] = input_king.at(1) - '1';
	stone[0] = input_stone.at(0) - 'A';
	stone[1] = input_stone.at(1) - '1';

	while (move--) {
		cin >> this_move;
		move_to(this_move);
	}

	char king_row = king[0] + 'A';
	char stone_row = stone[0] + 'A';

	cout << king_row << king[1] + 1 << "\n";
	cout << stone_row << stone[1] + 1 << "\n";

	return 0;
}
