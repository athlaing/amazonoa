#pragma once
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
class OptimalUtilization
{
public:
	vector<vector<int>> solution(vector<vector<int>> a, vector<vector<int>> b, int target) {
		sort(a.begin(), a.end(), [](vector<int> x, vector<int> y) {return x[1] < y[1]; });
		sort(b.begin(), b.end(), [](vector<int> x, vector<int> y) {return x[1] < y[1]; });
		int m = a.size();
		int n = b.size();
		vector<vector<int>> result;
		int val = INT_MIN;
		int i = 0; int r = n - 1;
		while (i < m && r >= 0) {
			int sum = a[i][1] + b[r][1];
			if (sum > target) {
				r--;
			}
			else {
				if (val <= sum) {
					if (val < sum) {
						val = sum;
						result.clear();
					}
					result.push_back({ a[i][0], b[r][0] });
					int ind = r - 1;
					while (ind >= 0 && b[ind][1] == b[ind + 1][1]) {
						result.push_back({ a[i][0], b[ind--][0] });
					}
				}
				i++;
			}
		}
		return result;
	}


	bool test() {
		vector<vector<int>> a { {1, 8}, {2, 7}, {3, 14} };
		vector<vector<int>> b { {1, 5}, {2, 10}, {3, 14} };
		int target = 20;
		vector<vector<int>> res = solution(a, b, target);
		vector<vector<int>> ans = { {3, 1} };
		return ans == res;
	}
};

