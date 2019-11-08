#pragma once
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
class RollDice
{
public:
	int solution(vector<int> a) {
		int ans = INT_MAX;
		for (int i = 1; i < 7; i++) {
			int count = 0;
			for (int d : a) {
				if (d == i) {
					continue;
				} else if (i + d == 7) {
					count += 2;
				}
				else {
					count += 1;
				}
			}
			ans = min(ans, count);
		}
		return ans;
	}

	bool test() {
		vector<int> a{ 1, 1, 6 };
		int ans = 2;
		return ans == solution(a);
	}
};

