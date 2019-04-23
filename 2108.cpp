#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//통계학
//https://www.acmicpc.net/problem/2108
int map[51][51] = { 0 };
int go_row[4] = { 1,-1,0,0 };
int go_col[4] = { 0,0,-1,1 };
int N;

int main() {
	cin >> N;
	int input;
	int sum = 0; int max = -4000; int min = 4000;
	vector<int> numbers;
	int number_appear[8002] = {0};
	//num_app[0]=-4000의 출현빈도, num_app[4000]=0의 출현빈도
	for (int tc = 0; tc < N; tc++) {
		cin >> input;
		numbers.push_back(input);
		sum += input;
		number_appear[input + 4000]++;
		if (max < input) max = input;
		if (min > input) min = input;
	}

	//산술평균
	double avg = (double)sum / (double)N;
	cout << fixed;
	cout.precision(0);
	cout << avg << endl;

	//중앙값
	sort(numbers.begin(), numbers.end());
	int mid = (N - 1) / 2;
	cout << numbers.at(mid) << endl;

	//최빈값
	int frequent = 0;
	int most_freq;
	int dup = 0;
	for (int i = 0; i < 8002; i++) {
		if (number_appear[i] > 0) {
			if (number_appear[i] > frequent) {
				dup = 0;
				frequent = number_appear[i];
				most_freq = i - 4000;
			}
			else if (number_appear[i] == frequent) {
				dup++;
				if (dup < 2) most_freq = i - 4000;
			}
		}
	}
	cout << most_freq << endl;

	//범위
	cout << max - min << endl;

	return 0;
}