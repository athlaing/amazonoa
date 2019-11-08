#pragma once
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
class TreasureIslandII
{
public:
	int solution(vector<vector<char>> map) {
		vector<vector<bool>> visited(map.size(), vector<bool>(map[0].size()));
		queue<pair<int, int>> q;
		int res = 0;
		for (int i = 0; i < map.size(); i++) {
			for (int j = 0; j < map[i].size(); j++) {
				if (map[i][j] == 'S') {
					q.push({ i, j });
					visited[i][j] = true;
				}
			}
		}
		vector<pair<int, int>> o{ {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
		while (!q.empty()) {
			int size = q.size();
			while (size--) {
				pair<int, int> source = q.front();
				q.pop();
				if (map[source.first][source.second] == 'X') return res;
				for (pair<int, int> d : o) {
					pair<int, int> des{ source.first, source.second };
					des.first += d.first;
					des.second += d.second;
					if (!(des.first < 0 || des.first > map.size() - 1 || des.second < 0 || des.second > map[0].size() - 1)
						&& !visited[des.first][des.second] && map[des.first][des.second] != 'D') {
						q.push(des);
						visited[des.first][des.second] = true;
					}
				}
			}
			res++;
		}
		return 0;
	}

	bool test() {
		vector<vector<char>> map = { { 'S', 'O', 'O', 'S', 'S' },
									 { 'D', 'O', 'D', 'O', 'D' },
									 { 'O', 'O', 'O', 'O', 'X' },
									 { 'X', 'D', 'D', 'O', 'O' },
									 { 'X', 'D', 'D', 'D', 'O' } };
		int res = 3;
		int ans = solution(map);
		return ans == res;
	}
};

