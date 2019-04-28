#include <iostream>

using namespace std;
//Á¤¼ö »ï°¢Çü
//https://www.acmicpc.net/problem/1932

int N;
int tri[501][501] = { 0 };

int MAX(int a, int b) {
	if (a > b) return a;
	else return b;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++)
			cin >> tri[i][j];
	}

	for (int lv = 1; lv < N; lv++) {
		for (int idx = 0; idx <= lv; idx++) {
			if (idx == 0) tri[lv][idx] += tri[lv - 1][0];
			else if (idx == lv) tri[lv][idx] += tri[lv - 1][lv - 1];
			else tri[lv][idx] += MAX(tri[lv - 1][idx-1], tri[lv - 1][idx]);
		}
	}
	
	int result = 0;
	for (int i = 0; i < N; i++) if (result < tri[N - 1][i]) result = tri[N - 1][i];

	cout << result << endl;
	system("pause");
	return 0;
}