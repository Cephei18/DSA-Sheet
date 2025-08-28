#include<bits/stdc++.h>
using namespace std;

// Problem: Search in Rotated Sorted Array
// LeetCode: https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
       int l=0, r= nums.size()-1;

       while(l<=r){
        int mid = (l+r)/2;
        if(target == nums[mid]){
            return mid;
        }

        if(nums[l] <= nums[mid]){
            if(target> nums[mid] || target< nums[l]){
                l = mid + 1;
            }
            else{
                r = mid -1;
            }
        }
        else{
        if(target< nums[mid] || target > nums[r]){
            r = mid -1;
        }
        else{
            l = mid + 1;
        }
        }
       } 
    return -1;
    }
};

// Minimum Path Sum

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // dp has same structure as triangle
        vector<vector<int>> dp(n, vector<int>(n, 0));

        dp[0][0] = triangle[0][0]; // start point

        for (int r = 1; r < n; r++) {
            for (int i = 0; i <= r; i++) {
                if (i == 0) {
                    // only one parent (left edge)
                    dp[r][i] = triangle[r][i] + dp[r-1][i];
                } 
                else if (i == r) {
                    // only one parent (right edge)
                    dp[r][i] = triangle[r][i] + dp[r-1][i-1];
                } 
                else {
                    // both parents exist
                    dp[r][i] = triangle[r][i] + min(dp[r-1][i-1], dp[r-1][i]);
                }
            }
        }

        // answer is the minimum in the last row
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};
