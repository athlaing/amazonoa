#pragma once
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
class ZombieInfection
{
public:
	int solution(vector<vector<int>> grid) {
		queue<pair<int, int>> q;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 1) q.push({ i, j });
			}
		}
		int days = 0;
		vector<pair<int, int>> o{ {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
		while (!q.empty()) {
			int size = q.size();
			while (size--) {
				pair<int, int> source = q.front();
				q.pop();
				for (pair<int, int> dir : o) {
					pair<int, int> des = source;
					des.first += dir.first;
					des.second += dir.second;
					if (!(des.first < 0 || des.first > grid.size() - 1 || des.second < 0 || des.second > grid[0].size() - 1)
						&& grid[des.first][des.second] == 0) {
						grid[des.first][des.second] = 1;
						q.push(des);
					}
				}
			}
			days++;
		}
		return --days;
	}

	bool test() {
		vector<vector<int>> grid = { {0, 1, 1, 0, 1 },
									 {0, 1, 0, 1, 0 },
									 {0, 0, 0, 0, 1 },
									 {0, 1, 0, 0, 0 } };
		int res = 2;
		int ans = solution(grid);
		return ans == res;
	}
};

