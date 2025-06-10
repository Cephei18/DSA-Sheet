#include<bits/stdc++.h>
using namespace std;    

// Problem: Number of Islands
// LeetCode: https://leetcode.com/problems/number-of-islands/

class Solution {
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        int islands = 0;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == '1') {
                    dfs(grid, r, c);
                    islands++;
                }
            }
        }
        
        return islands;
    }
    
    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= grid.size() || 
            c >= grid[0].size() || grid[r][c] == '0') {
            return;
        }
        
        grid[r][c] = '0';
        for (int i = 0; i < 4; i++) {
            dfs(grid, r + directions[i][0], c + directions[i][1]);
        }
    }
};




// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
// Problem: Clone Graph
// LeetCode: https://leetcode.com/problems/clone-graph/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> oldToNew;
        return dfs(node, oldToNew);
    }

    Node* dfs(Node* node, map<Node*, Node*>& oldToNew) {
        if (node == nullptr) {
            return nullptr;
        }

        if (oldToNew.count(node)) {
            return oldToNew[node];
        }

        Node* copy = new Node(node->val);
        oldToNew[node] = copy;

        for (Node* nei : node->neighbors) {
            copy->neighbors.push_back(dfs(nei, oldToNew));
        }

        return copy;
    }
};

// Problem: Pacific Atlantic Water Flow
// LeetCode: https://leetcode.com/problems/pacific-atlantic-water-flow/


class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    if(heights.empty() || heights[0].empty()) return {};

     int rows = heights.size();
     int cols = heights[0].size();

     vector<vector<bool>>pacific(rows,vector<bool>(cols,false));
     vector<vector<bool>>atlantic(rows,vector<bool>(cols,false));

     for (int c = 0; c < cols; ++c) {
     dfs(0, c, pacific, heights, heights[0][c]); // Top row
     }
     for (int r = 0; r < rows; ++r) {
      dfs(r, 0, pacific, heights, heights[r][0]); // Left column
    }
     for (int c = 0; c < cols; ++c) {
     dfs(rows - 1, c, atlantic, heights, heights[rows - 1][c]); // Bottom row
    }
     for (int r = 0; r < rows; ++r) {
    dfs(r, cols - 1, atlantic, heights, heights[r][cols - 1]); // Right column
    }

    vector<vector<int>> result;
    for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
        if (pacific[r][c] && atlantic[r][c]) {
            result.push_back({r, c});
        }
    }
}
return result;

 
    }
     void dfs(int r,int c, vector<vector<bool>>& visited,
      vector<vector<int>>& heights, int prevHeight){
       
      if(r<0 || c<0 || r >= heights.size() ||
      c>= heights[0].size()) return;
      
    // Already visited
    if (visited[r][c]) return;

    // Height check — water can only flow from high to low or same
    if (heights[r][c] < prevHeight) return;

    // Mark as visited
    visited[r][c] = true;

      int dirn [4][2] = {
        {1,0},{-1,0},{0,1},{0,-1}
      };
      for( int i=0;i<4;i++){
        int NewR= r + dirn[i][0];
        int NewC = c + dirn[i][1];
        dfs(NewR, NewC, visited, heights, heights[r][c]);
      }
      

     }

};
