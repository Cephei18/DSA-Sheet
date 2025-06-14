#include <vector>
#include <unordered_set>    // For unordered_set
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// Problem: Contains Duplicate
// LeetCode: https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
   unordered_map<int,int> freq;

   for(int i:nums){
    freq[i]++;
   }
   for (auto& p : freq) {
     if (p.second > 1)
     return true;
   }
   return false;
}
};

// Problem: Valid Anagram
// LeetCode: https://leetcode.com/problems/valid-anagram/


class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length()) return false;

        unordered_map<char,int> s1;
        unordered_map<char,int> t1;

        for(char i : s){
          s1[i]++;
        }
        for(char j:t){
            t1[j]++;
        }
        return s1 == t1;
    }
};

// Approach 2 - This trick only works when you know the characters are lowercase English letters. 
//If input can contain uppercase or Unicode, you'll need a more flexible method (like a map or unordered_map<char, int>).

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        int count[26] = {0};

        for (int i = 0; i < s.length(); ++i) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; ++i) {
            if (count[i] != 0) return false;
        }

        return true;
    }
};

// Problem: Two Sum
// LeetCode: https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> numToIndex;  // number -> index map

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];  // find complement

            // check if complement exists in map
            if (numToIndex.find(complement) != numToIndex.end()) {
                // found a pair, return indices
                return {numToIndex[complement], i};
            }

            // store current number and index in map
            numToIndex[nums[i]] = i;
        }

        // no pair found
        return {};
    }
};
//  IMPORTANT: This solution assumes that there is exactly one solution, and you may not use the same element twice.
// Problem: Group Anagrams
// LeetCode: https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;
        
        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            anagramGroups[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& entry : anagramGroups) {
            result.push_back(entry.second);
        }

        return result;
    }
};

// Problem: Group Anagrams (Alternative Approach)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for (const auto& s : strs) {
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1; i < 26; ++i) {
                key += ',' + to_string(count[i]);
            }
            res[key].push_back(s);
        }
        vector<vector<string>> result;
        for (const auto& pair : res) {
            result.push_back(pair.second);
        }
        return result;
    }
};

// Problem: Top K Frequent Elements
// LeetCode: https://leetcode.com/problems/top-k-frequent-elements/


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int n : nums) {
            freq[n]++;
        }

        vector<pair<int, int>> elements;
        for (auto& p : freq) {
            elements.push_back({p.first, p.second});
        }

        sort(elements.begin(), elements.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second; // sort by frequency
        });

        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(elements[i].first);
        }

        return result;
    }
};


// [](pair<int, int>& a, pair<int, int>& b) — this is a lambda function (small inline function)

// a.second > b.second — says:

// “Put a before b if a has a higher frequency than b”

// Problem: Check if Words are Sorted in Alien Dictionary
// LeetCode: https://leetcode.com/problems/check-if-words-are-sorted-in-alien-dictionary/


class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int orderIndex[26] = {0};
        for (int i = 0; i < order.size(); ++i)
            orderIndex[order[i] - 'a'] = i;
        
        for (int i = 0; i < words.size() - 1; ++i) {
            string w1 = words[i], w2 = words[i + 1];
            int j = 0;
            
            for (; j < w1.size(); ++j) {
                if (j == w2.size()) return false;
                if (w1[j] != w2[j]) {
                    if (orderIndex[w1[j] - 'a'] > orderIndex[w2[j] - 'a'])
                        return false;
                    break;
                }
            }
        }
        return true;
    }
};

// Problem: Find the Town Judge
// LeetCode: https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> delta(n + 1, 0);
        
        for (auto& t : trust) {
            delta[t[0]]--;
            delta[t[1]]++;
        }
        
        for (int i = 1; i <= n; i++) {
            if (delta[i] == n - 1) {
                return i;
            }
        }
        
        return -1;
    }
};

// Problem: Valid Sudoku
// LeetCode: https://leetcode.com/problems/valid-sudoku/

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {

        for (int i = 0; i < 9; ++i)
        {
            unordered_set<char> row_set;
            for (int j = 0; j < 9; ++j)
            {
                char r_val = board[i][j];
                if (r_val == '.')
                    continue;
                if (row_set.count(r_val))
                    return false;
                row_set.insert(r_val);
            }
        }
        for (int i = 0; i < 9; ++i)
        {
            unordered_set<char> col_set;
            for (int j = 0; j < 9; ++j)
            {
                char c_val = board[j][i];
                if (c_val == '.')
                    continue;
                if (col_set.count(c_val))
                    return false;
                col_set.insert(c_val);
            }
        }
        for (int boxRow = 0; boxRow < 9; boxRow += 3)
        {
            for (int boxCol = 0; boxCol < 9; boxCol += 3)
            {
                unordered_set<char> box_set;
                for (int i = 0; i < 3; ++i)
                {
                    for (int j = 0; j < 3; ++j)
                    {
                        char val = board[boxRow + i][boxCol + j];
                        if (val == '.')
                            continue;
                        if (box_set.count(val))
                            return false;
                        box_set.insert(val);
                    }
                }
            }
        }

        return true;
    }
};
