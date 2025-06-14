#include <vector>
#include <unordered_set>    // For unordered_set
#include <iostream>
using namespace std;

// Function to check if there are any duplicate elements in the vector

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for(int i:nums){
        if(seen.count(i))
        return true;
        seen.insert(i);
    }
    return false;
    }
};

// 🔍 Line-by-line Explanation:
// unordered_set<int> seen;

// Creates an empty set named seen.

// This set will store all unique elements we’ve seen so far in the loop.

// for (int num : nums)

// Loops through each element in the input vector nums.

// if (seen.count(num)) return true;

// seen.count(num) checks whether num is already in the set.

// If it is, it means num has appeared before, so we found a duplicate → return true.

// seen.insert(num);

// If num was not already seen, we add it to the set.

// return false;

// If the loop completes without finding any duplicate, return false.

///////////////////////////////////////////////////////////////////////////////////////////////////

// Problem: Longest Consecutive Sequence
// LeetCode: https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                int length = 1;
                while (numSet.find(num + length) != numSet.end()) {
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};