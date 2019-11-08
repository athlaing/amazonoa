#pragma once
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<iostream>
using namespace std;
class FavoriteGenres
{
public:
	map<string, vector<string>> solution(map<string, vector<string>> userMap, map<string, vector<string>> genreMap) {
		map<string, string> song2genre;
		for (auto& i : genreMap) {
			for (auto& s : i.second) {
				song2genre[s] = i.first;
			}
		}
		map<string, vector<string>> res;
		for (auto& i : userMap) {
			map<string, int> count;
			int maxCount = INT_MIN;
			for (auto& s : i.second) {
				count[song2genre[s]]++;
				maxCount = max(maxCount, count[song2genre[s]]);
			}
			for (auto& c : count) {
				if (c.second == maxCount) {
					res[i.first].push_back(c.first);
				}
			}
		}
		return res;
	}

	bool test() {
		map<string, vector<string>> userMap;
		userMap["David"] = vector<string>{ "song1", "song2", "song3", "song4", "song8" };
		userMap["Emma"] = vector<string>{ "song5", "song6", "song7" };
		map<string, vector<string>> genreMap;
		genreMap["Rock"] = { "song1", "song3" };
		genreMap["Dubstep"] = { "song7" };
		genreMap["Techno"] = { "song2", "song4" };
		genreMap["Pop"] = { "song5", "song6" };
		genreMap["Jazz"] = { "song8", "song9" };
		map<string, vector<string>> ans = solution(userMap, genreMap);
		map<string, vector<string>> res;
		res["David"] = { "Rock", "Techno" };
		res["Emma"] = { "Pop" };
		return res == ans;
	}
};

