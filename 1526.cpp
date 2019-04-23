#include <iostream>
#include <queue>
using namespace std;
//가장 큰 금민수
//https://www.acmicpc.net/problem/1526
int main() {
	int n, ans;
	cin >> n;
	queue<int> kmNum;
	ans = 0;
	if (4 <= n) {
		ans = 4;
		kmNum.push(4);
	}
	if (7 <= n) {
		ans = 7;
		kmNum.push(7);
	}

	while (!kmNum.empty()) {
		int temp = kmNum.front();
		kmNum.pop();
		temp *= 10;
		if (temp + 4 <= n) {
			ans = temp + 4;
			kmNum.push(ans);
		}
		if (temp + 7 <= n) {
			ans = temp + 7;
			kmNum.push(ans);
		}
	}
	cout << ans << "\n";
	return 0;
}