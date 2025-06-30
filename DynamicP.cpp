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

// Problem: House Robber II
// LeetCode: https://leetcode.com/problems/house-robber-ii/


class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> nums1(nums.begin()+1,nums.end());
        vector<int> nums2(nums.begin(),nums.end()-1);
        return max(nums[0],max(helper(nums1),helper(nums2)));
    }

    private:
    int helper(vector<int> & nums){
        int rob1 = 0, rob2 = 0;
        for(int num:nums){
            int newRob = max(rob1 + num, rob2);
            rob1 = rob2;
            rob2 = newRob;
        }
        return rob2;
    }
};

// Problem: Longest Common Subsequence
// LeetCode: https://leetcode.com/problems/longest-common-subsequence/


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() < text2.size()) {
            swap(text1, text2);
        }

        vector<int> prev(text2.size() + 1, 0);
        vector<int> curr(text2.size() + 1, 0);

        for (int i = text1.size() - 1; i >= 0; --i) {
            for (int j = text2.size() - 1; j >= 0; --j) {
                if (text1[i] == text2[j]) {
                    curr[j] = 1 + prev[j + 1];
                } else {
                    curr[j] = max(curr[j + 1], prev[j]);
                }
            }
            swap(prev, curr);
        }

        return prev[0];
    }
};

// Problem: Coin Change
// LeetCode: https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       if(amount == 0) return 0;

       queue<int> q;
       q.push(0);
       vector<bool>seen(amount+1,false);

       seen[0] = true;
       int res = 0;

       while(!q.empty()){
        res++;
        int size = q.size();
        for(int i=0;i<size;i++){
            int cur = q.front();
            q.pop();
            for(int coin:coins){
                int nxt = cur + coin;
                if(nxt == amount) return res;
                if(nxt>amount || seen[nxt]) continue;
                seen[nxt] = true;
                q.push(nxt);
            }
        }
       }
       return -1;
    }
};
