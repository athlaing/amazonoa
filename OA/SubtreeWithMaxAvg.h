#pragma once
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
struct Node {
	int val;
	vector<Node*> children;
};

class SubtreeWithMaxAvg
{
private:
	int val = INT_MIN;
	Node* ans = NULL;
public:
	vector<double> solution(Node* root) {
		if (root == NULL) return { 0, 0 };

		double total = root->val;
		double count = 1;
		for (Node* child : root->children) {
			vector<double> tmp = solution(child);
			total += tmp[0];
			count += tmp[1];
		}
		double avg = total / count;
		if (avg > val) {
			val = avg;
			ans = root;
		}
		return vector<double> {total, count};
	}
};

