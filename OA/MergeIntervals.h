#pragma once
#include<vector>
#include<queue>
#include<set>
#include<iostream>
using namespace std;
class MergeIntervals
{
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
			if (a[0] == b[0]) {
				return a[1] > b[1];
			}
			return a[0] < b[0];
			});
		vector<vector<int>> ans;
		for (vector<int> i : intervals) {
			if (ans.size() == 0 || ans.back()[1] < i[0]) {
				ans.push_back(i);
			}
			else {
				ans.back()[1] = max(ans.back()[1], i[1]);
			}
		}
		return ans;
	}
};

