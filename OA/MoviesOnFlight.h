#pragma once
#include<vector>
#include<queue>
#include<map>
#include<iostream>
using namespace std;
class MoviesOnFlight
{
public:
	vector<int> solution(vector<int> movieDurations, int d) {
		d -= 30;
		vector<int> tmp(movieDurations);
		sort(movieDurations.begin(), movieDurations.end());
		int l = 0; 
		int r = movieDurations.size() - 1;
		vector<int> ans(2, INT_MIN);
		int mem = INT_MIN;
		while (l < r) {
			if (movieDurations[l] + movieDurations[r] <= d) {
				if (movieDurations[l] + movieDurations[r] > mem) {
					ans[0] = movieDurations[l];
					ans[1] = movieDurations[r];
					mem = movieDurations[l] + movieDurations[r];
				}
				l++;
			}
			else {
				r--;
			}
		}
		vector<int> res;
		for (int i = 0; i < tmp.size(); i++) {
			if (tmp[i] == ans[0] || tmp[i] == ans[1]) res.push_back(i);
		}
		return res;
	}

	bool test() {
		vector<int> movieDurations = { 90, 85, 75, 60, 120, 150, 125 };
		int d = 250;
		vector<int> res = { 0, 6 };
		vector<int> ans = solution(movieDurations, d);
		return res == ans;
	}
};

