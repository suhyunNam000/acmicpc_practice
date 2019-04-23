#include <iostream>
#include <vector>
#include <string>
using namespace std;
//스타트와 링크
//https://www.acmicpc.net/problem/14889
int num_people;
int ability[21][21];
int min_difference = 2000;

void divide_team(string team, int startsize, int linksize) {
	if (team.length() == num_people) {
		//start팀, link팀 나누기
		vector<int> start, link;
		for (int i = 0; i < num_people; i++) {
			if (team.at(i) == '1') {
				start.push_back(i);
			}	
			else link.push_back(i);
		}
		//min_difference 갱신
		int total_start = 0;
		int total_link = 0;
		//start팀 능력치 총합
		for (int i = 0; i < start.size(); i++) {
			for (int j = i+1; j < start.size(); j++) {
				total_start += (ability[start[i]][start[j]] + ability[start[j]][start[i]]);
			}
		}
		//link팀 능력치 총합
		for (int i = 0; i < link.size(); i++) {
			for (int j = i+1; j < link.size(); j++) {
				total_link += (ability[link[i]][link[j]] + ability[link[j]][link[i]]);
			}
		}
		int ability_diff;
		if (total_link > total_start) ability_diff = total_link - total_start;
		else ability_diff = total_start - total_link;

		if (min_difference > ability_diff) { 
			min_difference = ability_diff; }
		
		return;
	}
	else {
		if (startsize < (num_people / 2)) {
			divide_team(team + "1", startsize + 1, linksize);
		}
		if (linksize < (num_people / 2)) {
			divide_team(team + "0", startsize, linksize + 1);
		}
	}
}

int main() {
	cin >> num_people;
	for (int i = 0; i < num_people; i++) {
		for (int j = 0; j < num_people; j++) {
			cin >> ability[i][j];
		}
	}
	
	divide_team("", 0, 0);

	cout << min_difference << "\n";
	return 0;
}