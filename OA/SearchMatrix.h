#pragma once
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
class SearchMatrix
{
public:
	bool solution(vector<vector<int>>& matrix, int target) {
		int row = matrix.size() - 1;
		int col = 0;
		while (row >= 0 && col < matrix[0].size()) {
			if (matrix[row][col] > target) {
				row--;
			}
			else if (matrix[row][col] < target) {
				col++;
			}
			else {
				return true;
			}
		}
		return false;
	}
};

