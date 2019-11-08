#pragma once
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
class ConnectRopes
{
public:
	int solution(vector<int> ropes) {
		std::priority_queue<int, std::vector<int>, std::greater<int>> q;
		for (int r : ropes) q.push(r);
		int res = 0;
		while (q.size() > 1) {
			int r1 = q.top();
			q.pop();
			int r2 = q.top();
			q.pop();
			int tmp = r1 + r2;
			res += tmp;
			q.push(tmp);
		}
		return res;
	}

	bool test() {
		vector<int> ropes{ 20, 4, 8, 2 };
		int res = 54;
		return res == solution(ropes);
	}
};

