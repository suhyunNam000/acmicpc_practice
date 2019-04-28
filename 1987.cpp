#include <iostream>
#include<string>

using namespace std;
//¾ËÆÄºª
//https://www.acmicpc.net/problem/1987
int R, C,result;
string map[21];
int move_c[4] = { 1,-1,0,0 };
int move_r[4] = { 0,0,-1,1 };

int MAX(int a, int b) {
	if (a > b) return a;
	else return b;
}

void DFS(int r, int c,long long alphabet, int count) {
	alphabet |= (1 << (map[r][c] - 'A'));

	for (int i = 0; i < 4; i++) {
		int next_r = r + move_r[i];
		int next_c = c + move_c[i];

		if (next_r >= 0 && next_c >= 0 && next_r < R&&next_c < C) {
			if ( !(alphabet & (1 << (map[next_r][next_c] - 'A')) ) )//´ÙÀ½°Å°¡ ¾È¹â¾Ò´ø ¾ËÆÄºªÀÌ¸é
				DFS(next_r, next_c, alphabet, count + 1);
		}
		result = MAX(result, count);
	}
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) cin >> map[i];

	result = 0;
	DFS(0, 0, (long long)1 << 26, 1);
	cout << result << endl;

	system("pause");
	return 0;
}