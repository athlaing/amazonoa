#pragma once
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
class MinCost
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

	int solution(int N, vector<vector<int>>& edges, vector<vector<int>> nedges) {
		parent = vector<int>(N + 1);
		for (int i = 1; i <= N; i++) {
			parent[i] = i;
		}
		for (vector<int> edge : edges) {
			if (find(edge[0]) != find(edge[1])) {
				parent[edge[1]] = edge[0];
				N--;
			}
		}
		sort(nedges.begin(), nedges.end(), [](vector<int> a, vector<int> b) {
			return a[2] < b[2];
		});
		int ans = 0;
		for (vector<int> edge : nedges) {
			if (find(edge[0]) != find(edge[1])) {
				ans += edge[2];
				parent[edge[1]] = edge[0];
				N--;
				if (N == 0) return ans;
			}
		}
		return ans;
	}

	bool test() {
		int n = 6;
		vector<vector<int>> edges = { {1, 4}, {4, 5}, {2, 3} };
		vector<vector<int>> newEdges = { {1, 2, 5}, {1, 3, 10}, {1, 6, 2}, {5, 6, 5} };
		int res = solution(n, edges, newEdges);
		int ans = 7;
		return ans == res;
	}
};

