#include <iostream>
using namespace std;
//타일 채우기
//https://www.acmicpc.net/problem/2133
int main() {
	int dp[31];
	dp[0] = 1;  dp[1] = 0;	dp[2] = 3;

	int N;
	cin >> N;
	for (int i = 4; i <= N; i++) {
		if (i % 2 == 0)  dp[i] = 2;
		else dp[i] = 0;
	}

	int result[31];
	for (int i = 0; i <= N; i++) result[i] = 0;
	result[0] = 1;
	for (int i = 2; i <= N; i += 2) {
		for (int j = 2; j <= i; j += 2) {
			result[i] += dp[j] * result[i - j];
		}
	}

	cout << result[N];

	return 0;
}