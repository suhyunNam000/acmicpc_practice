#include <iostream>
using namespace std;
//피보나치 수
//https://www.acmicpc.net/problem/2747
int fibo_arr[46] = {0, 1};

int main() {
	
	for (int i = 2; i < 46; i++) {
		fibo_arr[i] = fibo_arr[i - 1] + fibo_arr[i - 2];
	}

	int n;
	cin >> n;

	cout << fibo_arr[n];

	return 0;
}