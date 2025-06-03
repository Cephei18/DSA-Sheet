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
