#pragma once
#include<vector>
#include<queue>
#include<set>
#include<iostream>
using namespace std;
class RepairEdges
{
private:
	vector<int> parent;

public:
	int find(int v) {
		if (parent[v] != v) {
			parent[v] = find(parent[v]);
		}
		return parent[v];
	}
	int solution(int n, vector<vector<int>> edges, vector<vector<int>> edgesToRepair) {
		set<pair<int, int>> e;
		int res = 0;
		parent = vector<int>(n + 1, -1);
		for (int i = 1; i <= n; i++) parent[i] = i;
		for (vector<int> edge : edgesToRepair) {
			e.insert({ edge[0], edge[1] });
		}
		for (vector<int> edge : edges) {
			if (!e.count({ edge[0], edge[1] })) {
				int ps = find(edge[0]);
				int pd = find(edge[1]);
				if (ps != pd) {
					n--;
					parent[ps] = pd;
				}
			}
		}
		sort(edgesToRepair.begin(), edgesToRepair.end(), [](vector<int> a, vector<int> b) {
			return a[2] < b[2];
		});
		for (vector<int> edge : edgesToRepair) {
			int ps = find(edge[0]);
			int pd = find(edge[1]);
			if (ps != pd) {
				res += edge[2];
				parent[ps] = pd;
				n--;
				if (n == 0) break;
			}
		}
		return res;
	}
	bool test() {
		int n = 5;
		vector<vector<int>> edges = { {1, 2}, {2, 3}, {3, 4}, {4, 5}, {1, 5} };
		vector<vector<int>> etr = { {1, 2, 12}, {3, 4, 30}, {1, 5, 8} };
		int res = solution(n, edges, etr);
		cout << res << endl;
		int ans = 20;
		return ans == res;
	}
};

