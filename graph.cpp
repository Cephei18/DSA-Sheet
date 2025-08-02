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

//Problem : Alien Dictionary
// LeetCode: https://leetcode.com/problems/alien-dictionary/    

class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        for (string w : words) {
            for (char c : w) {
                adj[c] = unordered_set<char>();
                indegree[c] = 0;
            }
        }
        
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i], w2 = words[i + 1];
            int minLen = min(w1.size(), w2.size());
            if (w1.size() > w2.size() && 
                w1.substr(0, minLen) == w2.substr(0, minLen)) {
                return "";
            }
            for (int j = 0; j < minLen; j++) {
                if (w1[j] != w2[j]) {
                    if (!adj[w1[j]].count(w2[j])) {
                        adj[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    break;
                }
            }
        }
        
        queue<char> q;
        for (auto &[c, deg] : indegree) {
            if (deg == 0) {
                q.push(c);
            }
        }
        
        string res;
        while (!q.empty()) {
            char char_ = q.front();
            q.pop();
            res += char_;
            for (char neighbor : adj[char_]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        return res.size() == indegree.size() ? res : "";
    }
};

// Problem: Rotting Oranges
// LeetCode: https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int fresh = 0;
        int time = 0;

        for(int r=0;r<grid.size();r++){
            for(int c=0;c<grid[0].size();c++){
                if(grid[r][c] == 1){
                    fresh++;
                }
                if(grid[r][c]==2){
                    q.push({r,c});
                }
            }
        }
        vector<pair<int,int>>dirn = {{0,1},{0,-1},{1,0},{-1,0}};
        while(fresh>0 && !q.empty()){
            int length = q.size();
            for(int i=0;i<length;i++){
                auto curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;

                for(const auto& dir: dirn){
                    int row = r + dir.first;
                    int col = c +dir.second;
                    if(row>=0 && row<grid.size() && col>=0 && 
                    col<grid[0].size() && grid[row][col] == 1){
                        grid[row][col] = 2;
                        q.push({row,col});
                        fresh--;
                    }
                }
            }
            time++;
        }
        return fresh == 0 ? time : -1;
    }
};

// Problem: Surrounded Regions
// LeetCode: https://leetcode.com/problems/surrounded-regions/


class Solution {
    int ROWS,COLS;
public:
     void solve(vector<vector<char>>& board) {
        ROWS = board.size();
        COLS = board[0].size();

        for (int r = 0; r < ROWS; r++) {
            if (board[r][0] == 'O') {
                capture(board, r, 0);
            }
            if (board[r][COLS - 1] == 'O') {
                capture(board, r, COLS - 1);
            }
        }

        for (int c = 0; c < COLS; c++) {
            if (board[0][c] == 'O') {
                capture(board, 0, c);
            }
            if (board[ROWS - 1][c] == 'O') {
                capture(board, ROWS - 1, c);
            }
        }

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                } else if (board[r][c] == 'T') {
                    board[r][c] = 'O';
                }
            }
        }
    }
     private: 
     void capture(vector<vector<char>>& board, int r, int c){
        if(r<0 || c<0 || r>= ROWS || c>= COLS || board[r][c] !='O'){
            return;
        }
        board[r][c] = 'T';
        int dirn[4][2] = { {1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0;i<4;i++){
            int newR = r + dirn[i][0];
            int newC = c + dirn[i][1];
            capture(board,newR,newC);
        }
     }
};

// Problem: Course Schedule II
// LeetCode: https://leetcode.com/problems/course-schedule-ii/

class Solution {
    vector<int> output;
    vector<int> indegree;
    vector<vector<int>> adj;
    
    void dfs(int node) {
        output.push_back(node);
        indegree[node]--;
        for (int nei : adj[node]) {
            indegree[nei]--;
            if (indegree[nei] == 0) {
                dfs(nei);
            }
        }
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        adj = vector<vector<int>>(numCourses);
        indegree = vector<int>(numCourses, 0);
        for (auto& pre : prerequisites) {
            indegree[pre[0]]++;
            adj[pre[1]].push_back(pre[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                dfs(i);
            }
        }

        if (output.size() != numCourses) return {};
        return output;
    }
};

// Problem: Word Ladder
// LeetCode: https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end() || 
            beginWord == endWord)
            return 0;
        int m = wordList[0].size();
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<string> qb, qe;
        unordered_map<string, int> fromBegin, fromEnd;
        qb.push(beginWord);
        qe.push(endWord);
        fromBegin[beginWord] = 1;
        fromEnd[endWord] = 1;
        
        while (!qb.empty() && !qe.empty()) {
            if (qb.size() > qe.size()) {
                swap(qb, qe);
                swap(fromBegin, fromEnd);
            }
            int size = qb.size();
            for (int k = 0; k < size; k++) {
                string word = qb.front();
                qb.pop();
                int steps = fromBegin[word];
                for (int i = 0; i < m; i++) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == word[i])
                            continue;
                        string nei = word.substr(0, i) + 
                                     c + word.substr(i + 1);
                        if (!wordSet.count(nei))
                            continue;
                        if (fromEnd.count(nei))
                            return steps + fromEnd[nei];
                        if (!fromBegin.count(nei)) {
                            fromBegin[nei] = steps + 1;
                            qb.push(nei);
                        }
                    }
                }
            }
        }
        return 0;
    }
};

// Problem: Dijkstra's Shortest Path Algorithm
// LeetCode: https://leetcode.com/problems/dijkstra-shortest-path/

class Solution {
public:
    // Implementation for Dijkstra's shortest path algorithm
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        // Build adjacency list
        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i < n; i++) {
            adj[i] = vector<pair<int, int>>();
        }

        // s = src, d = dst, w = weight
        for (vector<int>& edge : edges) {
            int s = edge[0], d = edge[1], w = edge[2];
            adj[s].push_back({d, w});
        }

        // Compute shortest paths
        unordered_map<int, int> shortest;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> minHeap; 
        minHeap.push({0, src});

        while (!minHeap.empty()) {
            pair<int, int> curr = minHeap.top();
            minHeap.pop();
            int w1 = curr.first, n1 = curr.second;

            if (shortest.find(n1) != shortest.end()) continue;
            shortest[n1] = w1;

            for (pair<int, int>& edge : adj[n1]) {
                int n2 = edge.first, w2 = edge.second;
                if (shortest.find(n2) == shortest.end()) {
                    minHeap.push({w1 + w2, n2});
                }
            }
        }

        // Fill in missing nodes
        for (int i = 0; i < n; i++) {
            if (shortest.find(i) == shortest.end()) {
                shortest[i] = -1;
            }
        }

        return shortest;
    }
};

// Problem: Word Search
// LeetCode: https://leetcode.com/problems/word-search/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;

        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int index) {
        if (index == word.size()) return true;

        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() ||
            board[r][c] != word[index]) {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '#';  // Mark as visited

        int dirn[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int k = 0; k < 4; ++k) {
            int newR = r + dirn[k][0];
            int newC = c + dirn[k][1];
            if (dfs(board, word, newR, newC, index + 1)) {
                return true;
            }
        }

        board[r][c] = temp;  // Backtrack
        return false;
    }
};


// Problem: Lowest Common Ancestor of a Binary Search Tree
// LeetCode: https://leetcode.com/problems/lowest-common-ancestor-of-a-binarysearch-tree/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;

        while (cur) {
            if (p->val > cur->val && q->val > cur->val) {
                cur = cur->right;
            } else if (p->val < cur->val && q->val < cur->val) {
                cur = cur->left;
            } else {
                return cur;
            }
        }
        return nullptr;
    }
};

// Problem: Implement Trie (Prefix Tree)
// LeetCode: https://leetcode.com/problems/implement-trie-prefix-tree/

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord = false;
};

class PrefixTree {
    TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (cur->children.find(c) == cur->children.end()) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->endOfWord = true;
    }

    bool search(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (cur->children.find(c) == cur->children.end()) {
                return false;
            }
            cur = cur->children[c];
        }
        return cur->endOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char c : prefix) {
            if (cur->children.find(c) == cur->children.end()) {
                return false;
            }
            cur = cur->children[c];
        }
        return true;
    }
};

// Problem: Word Dictionary
// LeetCode: https://leetcode.com/problems/word-dictionary/

class WordDictionary {
public:
    vector<string> store;

    WordDictionary() {}

    void addWord(string word) {
        store.push_back(word);
    }

    bool search(string word) {
        for (string w : store) {
            if (w.length() != word.length()) continue;
            int i = 0;
            while (i < w.length()) {
                if (w[i] == word[i] || word[i] == '.') {
                    i++;
                } else {
                    break;
                }
            }
            if (i == w.length()) {
                return true;
            }
        }
        return false;
    }
};

// Problem: Add and Search Word - Data structure design
// LeetCode: https://leetcode.com/problems/add-and-search-word-data-structure-design/

class TrieNode {
public:
    vector<TrieNode*> children;
    bool word;

    TrieNode() : children(26, nullptr), word(false) {}
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() : root(new TrieNode()) {}

    void addWord(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (cur->children[c - 'a'] == nullptr) {
                cur->children[c - 'a'] = new TrieNode();
            }
            cur = cur->children[c - 'a'];
        }
        cur->word = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }

private:
    bool dfs(string word, int j, TrieNode* root) {
        TrieNode* cur = root;

        for (int i = j; i < word.size(); i++) {
            char c = word[i];
            if (c == '.') {
                for (TrieNode* child : cur->children) {
                    if (child != nullptr && dfs(word, i + 1, child)) {
                        return true;
                    }
                }
                return false;
            } else {
                if (cur->children[c - 'a'] == nullptr) {
                    return false;
                }
                cur = cur->children[c - 'a'];
            }
        }
        return cur->word;
    }
};

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isWord;

    TrieNode() : isWord(false) {}

    void addWord(const string& word) {
        TrieNode* cur = this;
        for (char c : word) {
            if (!cur->children.count(c)) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->isWord = true;
    }
};

// Problem: Word Search II
// LeetCode: https://leetcode.com/problems/word-search-ii/

class Solution {
    unordered_set<string> res;
    vector<vector<bool>> visit;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& word : words) {
            root->addWord(word);
        }

        int ROWS = board.size(), COLS = board[0].size();
        visit.assign(ROWS, vector<bool>(COLS, false));

        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                dfs(board, r, c, root, "");
            }
        }
        return vector<string>(res.begin(), res.end());
    }

private:
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, string word) {
        int ROWS = board.size(), COLS = board[0].size();
        if (r < 0 || c < 0 || r >= ROWS || 
            c >= COLS || visit[r][c] || 
            !node->children.count(board[r][c])) {
            return;
        }

        visit[r][c] = true;
        node = node->children[board[r][c]];
        word += board[r][c];
        if (node->isWord) {
            res.insert(word);
        }

        dfs(board, r + 1, c, node, word);
        dfs(board, r - 1, c, node, word);
        dfs(board, r, c + 1, node, word);
        dfs(board, r, c - 1, node, word);

        visit[r][c] = false;
    }
};

// Problem: Bipartite Graph
// LeetCode: https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; ++i) {
            if (color[i] == -1) {
                if (!dfs(graph, i, 0, color)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool dfs(vector<vector<int>>& graph, int node, int c, vector<int>& color) {
        if (color[node] != -1) {
            return color[node] == c;
        }

        color[node] = c;

        for (int nei : graph[node]) {
            if (color[nei] == -1) {
                if (!dfs(graph, nei, 1 - c, color)) {
                    return false;
                }
            } else if (color[nei] == c) {
                return false;
            }
        }

        return true;
    }
};

// Problem: Find Eventual Safe States
// LeetCode: https://leetcode.com/problems/find-eventual-safe-states/

class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, vector<int>& color) {
        if (color[node] != -1) {
            return color[node] == 2; // return true only if already marked safe
        }

        color[node] = 1; // mark as visiting

        for (int nei : graph[node]) {
            if (!dfs(graph, nei, color)) {
                return false; // found a cycle
            }
        }

        color[node] = 2; // mark as safe
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // -1 = unvisited
        vector<int> res;

        for (int i = 0; i < n; i++) {
            if (dfs(graph, i, color)) {
                res.push_back(i); // safe node
            }
        }

        return res;
    }
};

// Problem: Course Schedule
// LeetCode: https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);  // adjacency list

        // Build the graph
        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            graph[prereq].push_back(course);  // prereq → course
        }

        vector<int> color(numCourses, -1);  // -1 = unvisited, 1 = visiting, 2 = safe

        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i, graph, color)) {
                return false;  // cycle found
            }
        }

        return true;  // no cycles → all courses can be finished
    }

    bool dfs(int node, vector<vector<int>>& graph, vector<int>& color) {
        if (color[node] != -1) {
            return color[node] == 2;  // already visited → return whether it's safe
        }

        color[node] = 1;  // mark as visiting

        for (int nei : graph[node]) {
            if (!dfs(nei, graph, color)) {
                return false;  // cycle detected
            }
        }

        color[node] = 2;  // mark as safe
        return true;
    }
};

// Problem: Count Paths in a Grid
// LeetCode: https://leetcode.com/problems/count-paths-in-a-grid/

class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();

        if (grid[0][0] == 1 || grid[R-1][C-1] == 1) return 0; // blocked start/end

        vector<vector<bool>> visited(R, vector<bool>(C, false));
        int totalPaths = 0;

        dfs(grid, 0, 0, visited, totalPaths);
        return totalPaths;
    }

    void dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& visited, int& totalPaths) {
        int R = grid.size(), C = grid[0].size();

        // Base cases
        if (r < 0 || c < 0 || r >= R || c >= C || grid[r][c] == 1 || visited[r][c]) return;

        // Reached destination
        if (r == R-1 && c == C-1) {
            totalPaths++;
            return;
        }

        visited[r][c] = true;

        int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        for (int i = 0; i < 4; i++) {
            int newR = r + dir[i][0];
            int newC = c + dir[i][1];
            dfs(grid, newR, newC, visited, totalPaths);
        }

        visited[r][c] = false; // backtrack
    }
};

// Problem: BFS Traversal
// LeetCode: https://leetcode.com/problems/bfs-traversal/


int BFS(vector<vector<int>>& grid, int startR, int startC) {
    int R = grid.size();           // Number of rows
    int C = grid[0].size();        // Number of columns

    // Queue to store the cells we need to explore next
    queue<pair<int, int>> q;

    // Visited matrix to avoid revisiting the same cell
    vector<vector<bool>> visited(R, vector<bool>(C, false));

    // Start from the given cell
    q.push({startR, startC});
    visited[startR][startC] = true;

    // Direction vectors: down, up, right, left
    int dir[4][2] = {
        {1, 0},   // down
        {-1, 0},  // up
        {0, 1},   // right
        {0, -1}   // left
    };

    // While there are still cells to explore
    while (!q.empty()) {
        // Get the front cell and remove it from queue
        auto [r, c] = q.front(); 
        q.pop();

        // You can perform some action here, like counting steps or checking condition

        // Explore all 4 directions
        for (int i = 0; i < 4; ++i) {
            int nr = r + dir[i][0];  // new row
            int nc = c + dir[i][1];  // new column

            // Check boundaries and whether the cell is already visited or blocked
            if (nr >= 0 && nc >= 0 && nr < R && nc < C &&
                !visited[nr][nc] && grid[nr][nc] == 0) {

                // Mark new cell as visited and add to queue
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }

    return 1; // Change based on what the problem wants (e.g. steps, bool, count, etc.)
}
