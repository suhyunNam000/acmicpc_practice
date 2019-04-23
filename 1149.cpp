#include <iostream>
using namespace std;
//RGB거리
//https://www.acmicpc.net/problem/1149
int Min(int a, int b) {
	if (a < b) return a;
	else return b;
}

int house_color[1001][3];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		//R:0 G:1 B:2
		cin >> house_color[i][0] >> house_color[i][1] >> house_color[i][2];
	}

	int current_cost[1001][3];
	current_cost[0][0] = house_color[0][0];//R
	current_cost[0][1] = house_color[0][1];//G
	current_cost[0][2] = house_color[0][2];//B
	
	for (int h_idx = 1; h_idx < N; h_idx++) {
		for (int rgb = 0; rgb < 3; rgb++) {
			if (rgb == 0)	current_cost[h_idx][rgb] = house_color[h_idx][rgb] + Min(current_cost[h_idx - 1][1], current_cost[h_idx - 1][2]);
			else if(rgb == 1) current_cost[h_idx][rgb] = house_color[h_idx][rgb] + Min(current_cost[h_idx - 1][0], current_cost[h_idx - 1][2]);
			else if(rgb == 2) current_cost[h_idx][rgb] = house_color[h_idx][rgb] + Min(current_cost[h_idx - 1][0], current_cost[h_idx - 1][1]);
		}
	}

	int result;
	if (current_cost[N - 1][0] < current_cost[N - 1][1]) result = Min(current_cost[N - 1][0], current_cost[N - 1][2]);
	else result = Min(current_cost[N - 1][1], current_cost[N - 1][2]);

	cout << result;

	return 0;
}