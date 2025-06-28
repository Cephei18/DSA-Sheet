#include<bits/stdc++.h>
using namespace std;   

// Problem: Climbing Stairs
// LeetCode: https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2){
            return n;
        }
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;

        for(int i=3;i<= n; i++){
            dp[i] =dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

// Problem: House Robber
// LeetCode: https://leetcode.com/problems/house-robber/

class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0, rob2 = 0;

        for (int num : nums) {
            int temp = max(num + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
};