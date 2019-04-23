#include <queue>
#include <iostream>  
#include <functional> 
using namespace std;
//놀이 공원
//https://www.acmicpc.net/problem/1561

// global
int N, M;
// 0번은 사용 X 
int arrM[10001];

int main() {
	cin >> N >> M;
	for (int m_idx = 1; m_idx <= M; m_idx++) {
		int sub_m;
		cin >> sub_m;
		arrM[m_idx] = sub_m;
	}

	// 이진탐색
	// init
	long long left = 0;
	long long right = 60000000000;
	long long total_time = 0;

	if (N <= M) {
		cout << N;
		return 0;
	}

	// 해당 시간에 탑승할 수 있는 사람들을 세고 
	// N 보다 크거나 같으면 time 을 갱신한다. 
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long ridden_person = M;
		for (int m_idx = 1; m_idx <= M; m_idx++) {
			ridden_person += mid / arrM[m_idx];
		}

		if (ridden_person >= N) {
			total_time = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}

	}

	// 찾은 시간의 이전 시간까지(total_time - 1) 탑승한 인원을 전부 더한다. 
	long long ridden_person = M;
	for (int m_idx = 1; m_idx <= M; m_idx++) {
		ridden_person += ((total_time - 1) / arrM[m_idx]);
	}

	// 찾은 시간에 탑승한 사람을 확인한다 
	for (int m_idx = 1; m_idx <= M; m_idx++) {
		if (total_time%arrM[m_idx] == 0) ridden_person++;
		if (ridden_person == N) {
			cout << m_idx << '\n';
			break;
		}
	}

	return 0;
}