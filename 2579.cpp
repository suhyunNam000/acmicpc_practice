#include <iostream>
//계단 오르기
//https://www.acmicpc.net/problem/2579
using namespace std;

int MAX(int a, int b) {
	if (a > b) return a;
	else return b;
}

int main() {
	int N;
	cin >> N;
	
	int stairs[301];
	bool check_stairs[301];
	for (int i = 0; i < N; i++) {
		cin >> stairs[i];
		check_stairs[i] = false;
	}

	int max_stairs[301];
	max_stairs[0] = stairs[0];
	max_stairs[1] = stairs[1]+stairs[0];

	for (int i = 2; i < N; i++) {
		max_stairs[i] = MAX(max_stairs[i-3]+stairs[i-1], max_stairs[i-2]) + stairs[i];
	}
	cout << max_stairs[N - 1];

	return 0;
}