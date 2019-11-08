#pragma once
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<iostream>
using namespace std;
class MostCommonWords
{
public:
	vector<string> solution(vector<string> wordsToExclude, string text) {
		set<string> wte;
		for (string w : wordsToExclude) {
			wte.insert(lower(w));
		}
		string word = "";
		map<string, int> count;
		int val = INT_MIN;
		for (int i = 0; i <= text.size(); i++) {
			if (i == text.size() || !isalpha(text[i])) {
				if (word.size() == 0) continue;
				if (!wte.count(word)) {
					count[word]++;
					val = max(val, count[word]);
				}
				word = "";
			}
			else {
				word += tolower(text[i]);
			}
		}
		vector<string> res;
		for (auto c : count) {
			if (c.second == val) {
				res.push_back(c.first);
			}
		}
		return res;
	}

	string lower(string& a) {
		for (int i = 0; i < a.size(); i++) {
			a[i] = tolower(a[i]);
		}
		return a;
	}

	bool test() {
		vector<string> wordsToExclude = { "and", "he", "the", "to", "is", "Jack", "Jill" };
		string text = "Jack and Jill went to the market to buy bread and cheese. Cheese is Jack's and Jill's favorite food.";
		vector<string> ans = solution(wordsToExclude, text);
		vector<string> res{ "cheese", "s" };
		return res == ans;
	}
};

