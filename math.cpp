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

// Problem: Insert Interval
// LeetCode: https://leetcode.com/problems/insert-interval/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int newStart = newInterval[0];
        int newEnd = newInterval[1];
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            if (intervals[i][0] > newEnd) {
                res.push_back(newInterval);
                copy(intervals.begin() + i, intervals.end(), back_inserter(res));
                return res;
            } else if (intervals[i][1] < newStart) {
                res.push_back(intervals[i]);
            } else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        res.push_back(newInterval);
        return res;
    }
};

// Problem: Set Matrix Zeroes
// LeetCode: https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        bool rowZero = false;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (matrix[r][c] == 0) {
                    matrix[0][c] = 0;
                    if (r > 0) {
                        matrix[r][0] = 0;
                    } else {
                        rowZero = true;
                    }
                }
            }
        }

        for (int r = 1; r < ROWS; r++) {
            for (int c = 1; c < COLS; c++) {
                if (matrix[0][c] == 0 || matrix[r][0] == 0) {
                    matrix[r][c] = 0;
                }
            }
        }

        if (matrix[0][0] == 0) {
            for (int r = 0; r < ROWS; r++) {
                matrix[r][0] = 0;
            }
        }

        if (rowZero) {
            for (int c = 0; c < COLS; c++) {
                matrix[0][c] = 0;
            }
        }
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

// Problem: Spiral Matrix
// LeetCode: https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, 
                                             {0, -1}, {-1, 0}};
        vector<int> steps = {matrix[0].size(), matrix.size() - 1};

        int r = 0, c = -1, d = 0;
        while (steps[d % 2]) {
            for (int i = 0; i < steps[d % 2]; i++) {
                r += directions[d].first;
                c += directions[d].second;
                res.push_back(matrix[r][c]);
            }
            steps[d % 2]--;
            d = (d + 1) % 4;
        }
        return res;
    }
};

// Problem: Meeting Rooms
// LeetCode: https://leetcode.com/problems/meeting-rooms/

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
       sort(intervals.begin(),intervals.end(),[](auto& x, auto& y){
        return x.start < y.start;
       });
       for(int i=1;i<intervals.size();++i){
        if(intervals[i].start<intervals[i-1].end){
            return false;
        }
       }
       return true;
        
    }
};

// Problem: Non-overlapping Intervals
// LeetCode: https://leetcode.com/problems/non-overlapping-intervals/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });
        int res = 0;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (start < prevEnd) {
                res++;
            } else {
                prevEnd = end;
            }
        }
        return res;
    }
};

// Problem: Merge Intervals
// LeetCode: https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        output.push_back(intervals[0]);

        for (auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            int lastEnd = output.back()[1];

            if (start <= lastEnd) {
                output.back()[1] = max(lastEnd, end);
            } else {
                output.push_back({start, end});
            }
        }
        return output;
    }
// Problem: Insert Interval
// LeetCode: https://leetcode.com/problems/insert-interval/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0;
        int n = intervals.size();

        while(i<n && intervals[i][1]<newInterval[0]){
            result.push_back(intervals[i]);
            i++;
        }

        while(i<n && intervals[i][0]<=newInterval[1]){
            newInterval[0] = min(intervals[i][0],newInterval[0]);
            newInterval[1] = max(intervals[i][1],newInterval[1]);
            i++;
        }
        result.push_back(newInterval);

        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
// Problem: Koko Eating Bananas
// LeetCode: https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = right;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            long long hours = 0;
            for(int pile : piles) {
                hours += (pile + mid - 1) / mid; // ceil(pile / mid)
            }

            if(hours <= h) {
                ans = mid;
                right = mid - 1; // try smaller k
            } else {
                left = mid + 1; // need larger k
            }
        }

        return ans;
    }
};
