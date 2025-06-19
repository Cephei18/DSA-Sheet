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

// Problem: Container With Most Water
// LeetCode: https://leetcode.com/problems/container-with-most-water/


class Solution {
public:
    int maxArea(vector<int>& heights) {
         
        int l = 0;
        int r = heights.size()-1;
        int maxA = 0;
        while(l<r){
         int area = (r-l) * min(heights[l],heights[r]);
         maxA = max(area,maxA);
           if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maxA;

    }
};

// Problem: Trapping Rain Water
// LeetCode: https://leetcode.com/problems/trapping-rain-water/


class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        int l = 0, r = height.size() - 1;
        int leftMax = height[l], rightMax = height[r];
        int res = 0;
        while (l < r) {
            if (leftMax < rightMax) {
                l++;
                leftMax = max(leftMax, height[l]);
                res += leftMax - height[l];
            } else {
                r--;
                rightMax = max(rightMax, height[r]);
                res += rightMax - height[r];
            }
        }
        return res;
    }
};

// Problem: Best Time to Buy and Sell Stock
// LeetCode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0;
        int r=1;
        int maxP = 0;
        while(r<prices.size()){
            if(prices[l]<prices[r]){
                int profit = prices[r]-prices[l];
                maxP = max(maxP,profit);
            }
            else{l=r;}
            r++;
        }
        return maxP;
    }
};

// Problem: Longest Substring Without Repeating Characters
// LeetCode: https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int l = 0;
        int res = 0;

        for (int r = 0; r < s.size(); r++) {
            while (charSet.find(s[r]) != charSet.end()) {
                charSet.erase(s[l]);
                l++;
            }
            charSet.insert(s[r]);
            res = max(res, r - l + 1);
        }
        return res;
    }
};

// Problem: Remove Duplicates from Sorted Array
// LeetCode: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0;
        while (r < n) {
            nums[l] = nums[r];
            while (r < n && nums[r] == nums[l]) {
                r++;
            }
            l++;
        }
        return l;
    }
};

// Problem: Remove Duplicates from Sorted Array II
// LeetCode: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;  // insert position
        for (int n : nums) {
            if (i < 2 || n != nums[i - 2]) {
                nums[i++] = n;
            }
        }
        return i;
    }
};
