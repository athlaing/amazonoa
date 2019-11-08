#pragma once
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
class KNearestPostOffices
{
public:
	vector<vector<int>> solution(vector<vector<int>> postOffices, pair<int, int> y, int k) {
		for (vector<int>& p : postOffices) {
			p.push_back(y.first);
			p.push_back(y.second);
		}
		sort(postOffices.begin(), postOffices.end(), [](vector<int> a, vector<int> b) {
			return (a[0] - a[2]) * (a[0] - a[2]) + (a[1] - a[3]) * (a[1] - a[3]) <
				(b[0] - b[2]) * (b[0] - b[2]) + (b[1] - b[3]) * (b[1] - b[3]);
		});
		vector<vector<int>> res;
		for (int i = 0; i < k; i++) {
			res.push_back({ postOffices[i][0], postOffices[i][1] });
		}
		return res;
	}

	bool test() {
		vector<vector<int>> postOffices{ {-16, 5}, {-1, 2}, {4, 3}, {10, -2}, {0, 3}, {-5, -9} };
		pair<int, int> y{ 0, 0 };
		int k = 3;
		vector<vector<int>> ans = solution(postOffices, y, k);
		vector<vector<int>> res{ {-1, 2}, {0, 3}, {4, 3} };
		return res == ans;
	}
};

