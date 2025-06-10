#include<bits/stdc++.h>
using namespace std;

// Problem: Two Sum II - Input array is sorted
// LeetCode: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size()-1 ;
        while(i<j){
        if(nums[i]+nums[j] == target){
            return {i,j};
        }
        else if(nums[i]+nums[j] < target){i++;}
        if(nums[i]+nums[j] > target){j--;}
        }
        return {}; 
   }
};


// Problem: 3Sum
// LeetCode: https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for (int i = 0; i < n - 2; ++i) {
            // Skip duplicates
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    // Skip duplicates
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;
    }
};


// Problem: Valid Palindrome
// LeetCode: https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        // Convert to lowercase
        for (char& c : s) {
            c = tolower(c);
        }

        // Remove non-alphanumeric characters
        s.erase(remove_if(s.begin(), s.end(), [](char c) {
            return !isalnum(static_cast<unsigned char>(c));
        }), s.end());

        // Two-pointer check for palindrome
        int i = 0;
        int j = s.length() - 1;

        while (i <= j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }
};
