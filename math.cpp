#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;


// LeetCode 48: Rotate Image
// https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Reverse the matrix vertically
        reverse(matrix.begin(), matrix.end());

        // Transpose the matrix
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i + 1; j < matrix[i].size(); ++j)
                swap(matrix[i][j], matrix[j][i]);
        }
    }
};