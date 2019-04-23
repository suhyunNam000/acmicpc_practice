#include <iostream>
using namespace std;
//별 찍기 - 1
//https://www.acmicpc.net/problem/2438
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++)cout << "*";
		cout << "\n";
	}

	return 0;
}