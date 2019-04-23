#include <iostream>
using namespace std;
//오일러 회로
//https://www.acmicpc.net/problem/1199
int N;
int graph[1001][1001] = { 0 };
int degree[1001] = { 0 };

void DFS(int node) {
	for (int i = 0; i < N; i++) {
		while (graph[node][i] > 0) {
			graph[node][i] --;
			graph[i][node] --;

			DFS(i);
		}
	}
	cout << node + 1 << " ";
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j]; 
			degree[i] += graph[i][j];
			degree[j] += graph[i][j];
		}
	}
	bool canEuler = true;
	for (int i = 0; i < N; i++) {
		degree[i] /= 2;
		if (degree[i] % 2 != 0) {
			canEuler = false;
			break;
		}
	}

	if (canEuler) {
		DFS(0);
		cout << "\n";
	}
	else { cout << -1 << "\n"; }

	return 0;
}