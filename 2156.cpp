#include <iostream>
using namespace std;
//포도주 시식
//https://www.acmicpc.net/problem/2156
int glass[10001];
int dp[10001];

int max(int a, int b) {
	if (a > b)return a;
	else return b;
}

int main() {
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> glass[i];
		dp[i] = 0;
	}
	if (n == 1) {
		cout << glass[0] << endl;
		return 0;
	}

	dp[0] = glass[0];
	dp[1] = glass[1] + glass[0];
	if (n == 2) {
		cout << dp[1] << endl;
		return 0;
	}
	dp[2] = max(glass[0] + glass[2], glass[1] + glass[2]);
	dp[2] = max(dp[2], dp[1]);
	if (n == 3) {
		cout << dp[2] << endl;
		return 0;
	}

	for (int i = 3; i < n; i++) {
		dp[i] = max(dp[i - 3] + glass[i-1], dp[i-2])+glass[i];
		dp[i] = max(dp[i], dp[i - 1]);
	}

	cout << dp[n - 1] << endl;
	return 0;
}