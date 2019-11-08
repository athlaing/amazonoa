#pragma once
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class ReorderLog
{
public:
	vector<string> solution(vector<string>& logs) {
		vector<pair<string, string>> alpha;
		vector<string> digit;
		for (string& s : logs) {
			int i = 0;
			while (s[i] != ' ') i++;
			if (isalpha(s[i + 1])) alpha.push_back({ s.substr(0, i), s.substr(i + 1) });
			else digit.push_back(s);
		}
		sort(alpha.begin(), alpha.end(), [](pair<string, string> a, pair<string, string> b) {
			string aStr = a.second + a.first;
			string bStr = b.second + b.first;
			return aStr < bStr;
			});
		int i = 0;
		for (auto p : alpha) {
			logs[i++] = p.first + " " + p.second;
		}
		for (string& s : digit) {
			logs[i++] = s;
		}
		return logs;
	}
};

