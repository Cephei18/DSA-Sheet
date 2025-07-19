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
//