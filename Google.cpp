// This sheet will have all the problems that have been asked in the Google interview.
//  We will cover problems related to graphs, trees, and dynamic programming.
// First mention problem name and then its link.

// Topic - Graphs 

// Problem: Number of Islands
// LeetCode: https://leetcode.com/problems/number-of-islands/

// Problem: Valid Tree
// LeetCode: https://leetcode.com/problems/valid-tree/

// Problem: Clone Graph
// LeetCode: https://leetcode.com/problems/clone-graph/

// Problem: Pacific Atlantic Water Flow
// LeetCode: https://leetcode.com/problems/pacific-atlantic-water-flow/

// Problem: Surrounded Regions
// LeetCode: https://leetcode.com/problems/surrounded-reg

// Problem: Island Perimeter
// LeetCode: https://leetcode.com/problems/island-perimeter/

// Problem: Max Area of Island
// LeetCode: https://leetcode.com/problems/max-area-of-island/

// Problem: Course Schedule
// LeetCode: https://leetcode.com/problems/course-schedule/

// Problem: Find the Maximum Number of Fish in a Pond
// LeetCode: https://leetcode.com/problems/find-the-maximum-number-of-fish-in-a-pond/

// Problem: Course Schedule II
// LeetCode: https://leetcode.com/problems/course-schedule-ii/

// Problem: Number of Connected Components in an Undirected Graph
// LeetCode: https://leetcode.com/problems/number-of-connected-components-in-an-undirected

// Problem: Find Eventual Safe States
// LeetCode: https://leetcode.com/problems/find-eventual-safe-states/

// Problem: Find the Town Judge
// LeetCode: https://leetcode.com/problems/find-the-town-judge/


// Problem: Find the Redundant Connection
// LeetCode: https://leetcode.com/problems/find-the-redundant-connection/

// Problem: Find the Redundant Directed Connection
// LeetCode: https://leetcode.com/problems/find-the-redundant-directed-connection

// Problem: Find the Minimum Height Trees
// LeetCode: https://leetcode.com/problems/find-minimum-height-trees/

// Problem: Find the Longest Path in a Directed Acyclic Graph
// LeetCode: https://leetcode.com/problems/find-the-longest-path-in-a-directed-acyclic-graph/

// Problem: Find the Shortest Path in a Grid with Obstacles Elimination
// LeetCode: https://leetcode.com/problems/find-the-shortest-path-in-a-grid-withobstacles-elimination/

// Problem: Find the Minimum Number of Vertices to Reach All Nodes
// LeetCode: https://leetcode.com/problems/find-the-minimum-number-of-vertices-to-reach-all-nodes/

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        vector<vector<int>> indegree(ROWS, vector<int>(COLS, 0));
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, 
                                          {0, -1}, {0, 1}};
        
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                for (auto& d : directions) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr >= 0 && nr < ROWS && nc >= 0 && 
                        nc < COLS && matrix[nr][nc] < matrix[r][c]) {
                        indegree[r][c]++;
                    }
                }
            }
        }
        
        queue<pair<int, int>> q;
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (indegree[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }
        
        int LIS = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [r, c] = q.front();
                q.pop();
                for (auto& d : directions) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr >= 0 && nr < ROWS && nc >= 0 && 
                        nc < COLS && matrix[nr][nc] > matrix[r][c]) {
                        if (--indegree[nr][nc] == 0) {
                            q.push({nr, nc});
                        }
                    }
                }
            }
            LIS++;
        }
        return LIS;
    }
};