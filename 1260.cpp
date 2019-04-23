#include <iostream>
#include <stack>
#include <queue>
using namespace std;
//DFS와 BFS
//https://www.acmicpc.net/problem/1260
queue<int> BFS;
int N, M, V;
bool visited[1001];
int graph[1001][1001];

void f_dfs(int start) {
	cout << start << " ";
	visited[start] = true;
	
	for (int i = 1; i <= N; i++) {
		if ( graph[start][i] == 1 && !visited[i] ) {
			f_dfs(i);
		}
	}
	
}

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
		cout << front << " ";
		BFS.pop();
	}
	
}

int main() {
	
	cin >> N >> M >> V;
	
	for (int i = 1; i <= N; i++) { // creating vertexes
		visited[i] = false;
	}

	int from, to;
	for (int i = 0; i < M; i++) {	//getting edges
		cin >> from >> to;
		graph[from][to] = 1;
		graph[to][from] = 1;
	}

	f_dfs(V);
	cout << "\n";
	for (int i = 1; i <= N; i++) { // 초기화
		visited[i] = false;
	}
	f_bfs(V);


	return 0;
}