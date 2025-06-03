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
