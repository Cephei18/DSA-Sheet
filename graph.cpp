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

// Problem: Island Perimeter
// LeetCode: https://leetcode.com/problems/island-perimeter/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1) {
                    return dfs(i, j, grid); // ✅ fix here
                }
            }
        }
        return 0;
    }

    int dfs(int r, int c, vector<vector<int>>& grid) {
        // ✅ If out of bounds or water, contributes to perimeter
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0) {
            return 1;
        }

        // ✅ If already visited, don’t count again
        if(grid[r][c] == -1) return 0;

        // ✅ Mark as visited
        grid[r][c] = -1;

        // Explore all 4 directions and sum the perimeter
        return dfs(r + 1, c, grid) +
               dfs(r - 1, c, grid) +
               dfs(r, c + 1, grid) +
               dfs(r, c - 1, grid);
    }
};

//approach 2
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c]) {
                    res += 4;
                    if (r && grid[r - 1][c]) {
                        res -= 2;
                    }
                    if (c && grid[r][c - 1]) {
                        res -= 2;
                    }
                }
            }
        }
        return res;
    }
};

// Problem: Max Area of Island
// LeetCode: https://leetcode.com/problems/max-area-of-island

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty())return 0;

        int r = grid.size();
        int c = grid[0].size();

        int Marea = 0;

        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                if(grid[i][j]==1){
                    int area = dfs(i,j,grid);
                    Marea = max(Marea,area);
                }
                
            }
        }
        return Marea;
        
    }
    int dfs(int r, int c, vector<vector<int>>& grid) {
    if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != 1)
        return 0;

    grid[r][c] = -1; // mark visited
    int area = 1;

    // Directions: up, down, left, right
    int dirn[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    for (int i = 0; i < 4; i++) {
        int newR = r + dirn[i][0];
        int newC = c + dirn[i][1];
        area += dfs(newR, newC, grid);
    }

    return area;
}

};

// Problem: Find the Maximum Number of Fish in a Pond
// LeetCode: https://leetcode.com/problems/find-the-maximum-number-of-fish-in-a-pond/

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {

        if(grid.empty() || grid[0].empty())return 0;

        int r = grid.size();
        int c = grid[0].size();

        int MaxF = 0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]!=0){
                    int currentF = dfs(i,j,grid);
                    MaxF = max(MaxF,currentF);
                }
            }
        }
        return MaxF;
        
    }
    int dfs(int r, int c,vector<vector<int>>& grid){
        if(r<0 || c< 0|| r>= grid.size() || c>= grid[0].size()|| 
        grid[r][c] == 0) return 0;

        int Fish = grid[r][c];

         grid[r][c] = 0;

        int dirn[4][2] = {
            {1,0},{-1,0},{0,1},{0,-1}
        };

        for(int i=0;i<4;i++){
            int NewR = r+ dirn[i][0];
            int NewC = c + dirn[i][1];
            Fish+= dfs(NewR,NewC,grid);
        }

        return Fish;
    }
};

// Problem: Course Schedule 
// LeetCode: https://leetcode.com/problems/course-schedule/

class Solution {
    // Map each course to its prerequisites
    unordered_map<int, vector<int>> preMap;
    // Store all courses along the current DFS path
    unordered_set<int> visiting;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++) {
            preMap[i] = {};
        }
        for (const auto& prereq : prerequisites) {
            preMap[prereq[0]].push_back(prereq[1]);
        }

        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c)) {
                return false;
            }
        }
        return true;
    }

    bool dfs(int crs) {
        if (visiting.count(crs)) {
            // Cycle detected
            return false;
        }
        if (preMap[crs].empty()) {
            return true;
        }

        visiting.insert(crs);
        for (int pre : preMap[crs]) {
            if (!dfs(pre)) {
                return false;
            }
        }
        visiting.erase(crs);
        preMap[crs].clear();
        return true;
    }
};

//Problem: Valid Tree
// LeetCode: https://leetcode.com/problems/valid-tree/

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n - 1) {
            return false;
        }

        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visit;
        if (!dfs(0, -1, visit, adj)) {
            return false;
        }

        return visit.size() == n;
    }

private:
    bool dfs(int node, int parent, unordered_set<int>& visit, 
             vector<vector<int>>& adj) {
        if (visit.count(node)) {
            return false;
        }

        visit.insert(node);
        for (int nei : adj[node]) {
            if (nei == parent) {
                continue;
            }
            if (!dfs(nei, node, visit, adj)) {
                return false;
            }
        }
        return true;
    }
};

// Problem: Number of Connected Components in an Undirected Graph
// LeetCode: https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visit(n, false);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int res = 0;
        for (int node = 0; node < n; ++node) {
            if (!visit[node]) {
                dfs(adj, visit, node);
                res++;
            }
        }
        return res;
    }

private:
    void dfs(const vector<vector<int>>& adj, vector<bool>& visit, int node) {
        visit[node] = true;
        for (int nei : adj[node]) {
            if (!visit[nei]) {
                dfs(adj, visit, nei);
            }
        }
    }
};