#include <iostream>
#include <queue>
using namespace std;
//토마토
//https://www.acmicpc.net/problem/7576
typedef struct a {
	int row;
	int col;
} tomato;

int row, col;
int tomato_box[1001][1001];	//tomato_box[col][row]
queue<tomato> box;	//익은 토마토 큐

int main() {
	cin >> row >> col;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			cin >> tomato_box[i][j];

			if (tomato_box[i][j] == 1) {
				tomato temp;
				temp.col = i;	temp.row = j;
				box.push(temp);
			}
		}
	}
	
	int day = 0;
	int width = box.size();
	int dr[4] = { 0,0,-1,1 };
	int dc[4] = { -1,1,0,0 };
	while (!box.empty()) {
		if (width == 0) { day++; width = box.size();    }
		tomato crop = box.front();
		box.pop();
		width--;
		int r = crop.row; int c = crop.col;
		for (int i = 0; i < 4; i++) {
			if (r + dr[i] >= 0 && r + dr[i] < row &&
				c + dc[i] >= 0 && c + dc[i] < col) {
				if (tomato_box[c + dc[i]][r + dr[i]] == 0) {
					tomato_box[c + dc[i]][r + dr[i]] = 1;
					tomato temp;
					temp.row = r + dr[i]; temp.col = c + dc[i];
					box.push(temp);
				}
			}
		}
	}

	bool isAllCrop = true;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (tomato_box[i][j] == 0) { isAllCrop = false; break; }
		}
	}

	if (isAllCrop)	cout << day << endl;
	else cout << "-1" << endl;

	return 0;
}