#include <iostream>
using namespace std;
// 유기농 배추
//https://www.acmicpc.net/problem/1012
typedef struct p {
	int row;
	int col;
}PAIR;

int map[51][51] = { 0 };
int go_row[4] = { 1,-1,0,0 };
int go_col[4] = { 0,0,-1,1 };
int R, C, K;

void dfs(int r, int c) {
	map[r][c] = 0;
	for (int i = 0; i < 4; i++) {
		int now_r = r + go_row[i]; int now_c = c + go_col[i];
		if (now_r >= 0 && now_r < R && now_c >= 0 && now_c < C) {
			if (map[now_r][now_c] == 1) dfs(now_r, now_c);
		}
	}
	return;
}

int main() {
	int tc;
	cin >> tc;
	while (tc) {
		PAIR plant[2501];
		cin >> R >> C >> K;

		for (int i = 0; i<K; i++) {
			int r, c;
			cin >> r >> c;
			plant[i].row = r;	plant[i].col = c;
			map[r][c] = 1;
		}
		
		int count = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (map[i][j] == 1) {
					dfs(i, j);
					count++;
				}
			}
		}
		cout << count << endl;

		tc--;
	}
	
	return 0;
}