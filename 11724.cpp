#include <iostream>
#include <queue>
using namespace std;
//연결 요소의 개수
//https://www.acmicpc.net/problem/11724
queue<int> BFS;
int N, M;
bool visited[1001];
int graph[1001][1001];

void f_bfs(int start) {
	BFS.push(start);
	visited[start] = true;
	int front;
	while(!BFS.empty()) {
		front = BFS.front();
		for (int i = 1; i <= N; i++) {
			if (graph[front][i] == 1 && !visited[i]) {
				BFS.push(i);
				visited[i] = true;
			}
		}
		BFS.pop();
	}
}

int main() {
	
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) { // creating vertexes
		visited[i] = false;
	}

	int from, to;
	for (int i = 0; i < M; i++) {	//getting edges
		cin >> from >> to;
		graph[from][to] = 1;
		graph[to][from] = 1;
	}
	
	int result = 0;
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			result++;
			f_bfs(i);
		}
	}
	
	cout << result;

	return 0;
}