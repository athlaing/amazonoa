#pragma once
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Subtree
{
public:
	bool isSubtree(TreeNode* s, TreeNode* t) {
		return traverse(s, t);
	}

	bool traverse(TreeNode* s, TreeNode* t) {
		return s != NULL && (compare(s, t) || traverse(s->left, t) || traverse(s->right, t));
	}

	bool compare(TreeNode* x, TreeNode* y) {
		if (x == NULL && y == NULL) return true;
		if (x == NULL || y == NULL) return false;
		return(x->val == y->val) && compare(x->left, y->left) && compare(x->right, y->right);
	}
};

