#pragma once
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
class PartitionLabels
{
public:
	vector<int> partitionLabels(string S) {
		vector<int> last(26);
		for (int i = 0; i < S.size(); i++) {
			last[S[i] - 'a'] = i;
		}
		int j = 0; int anchor = 0;
		vector<int> ans;
		for (int i = 0; i < S.size(); i++) {
			j = max(j, last[S[i] - 'a']);
			if (i == j) {
				ans.push_back(i - anchor + 1);
				anchor = i + 1;
			}
		}
		return ans;
	}
};

