#pragma once
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
class PointofLattice
{
public:
	vector<int> solution(int AX, int AY, int BX, int BY) {
		int dx = BX - AX;
		int dy = BY - AY;
		int rx = dy;
		int ry = -dx;
		int x = abs(gcd(rx, ry));
		return vector<int> {BX + (rx / x), BY + (ry / x)};
	}

	int gcd(int a, int b) {
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}

	bool test() {
		vector<int> ans = solution(-1, 3, 3, 1);
		vector<int> res{ 2, -1};
		return res == ans;
	}
};

