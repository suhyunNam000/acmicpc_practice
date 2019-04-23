#include <iostream>
#include <algorithm>
using namespace std;
//수 정렬하기
//https://www.acmicpc.net/problem/2750
int main() {

	int n;
	cin >> n;

	int arr[1001];

	for (int i = 0; i<n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	for (int i = 0; i < n-1; i++) {
		cout << arr[i] <<endl;
	}
	cout << arr[n - 1];

	return 0;
}