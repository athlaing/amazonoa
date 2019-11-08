#pragma once
#include<vector>
#include<queue>
#include<set>
#include<iostream>
using namespace std;
class KDistinctChar
{
public:
	vector<string> solution(string s, int k) {
		set<string> ans;
		for (int i = 0; i < s.size() - k; i++) {
			string word = s.substr(i, k);
			if (unique(word)) {
				ans.insert(word);
			}
		}
		return vector<string>(ans.begin(), ans.end());
	}

	bool unique(string s) {
		vector<int> tmp(26);
		for (char c : s) {
			tmp[c - 'a']++;
			if (tmp[c - 'a'] > 1) return false;
		}
		return true;
	}

	bool test() {
		string s = "awaglknagawunagwkwagl";
		int k = 4;
		vector<string> ans = solution(s, k);
		for (string s : ans) cout << s << " ";
		return true;
	}
};

