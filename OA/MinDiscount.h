#pragma once
#include<vector>
#include<queue>
#include<set>
#include<iostream>
#include<stack>
using namespace std;
class MinDiscount
{
public:
	int solution(vector<int> prices) {
		stack<int> s;
		vector<int> discounts(prices.size());
		for (int i = prices.size() - 1; i >= 0; i--) {
			while (!s.empty() && s.top() > prices[i]) {
				s.pop();
			}
			if (!s.empty()) {
				discounts[i] = s.top();
			}
			s.push(prices[i]);
		}
		int total = 0;
		for (int i = 0; i < prices.size(); i++) {
			total += prices[i] - discounts[i];
		}
		return total;
	}

	bool test() {
		vector<int> prices{ 1, 3, 3, 2, 5 };
		int ans = solution(prices);
		cout << ans << endl;
		return true;
	}
};

