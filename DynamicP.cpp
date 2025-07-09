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

//BFS Solution

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


// DP Solution
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        dp[0] = 0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(coins[j] <= i){
                    dp[i] = min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        return dp[amount]> amount? -1: dp[amount];
    }
};

// Problem: Decode Ways 
// LeetCode: https://leetcode.com/problems/decode-ways/

class Solution {
public:
    int numDecodings(string s) {
        int dp = 0, dp2 = 0;
        int dp1 = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp = 0;
            } else {
                dp = dp1;
                if (i + 1 < s.size() && (s[i] == '1' || 
                    s[i] == '2' && s[i + 1] < '7')) {
                    dp += dp2;
                }
            }
            dp2 = dp1;
            dp1 = dp;
            dp = 0;
        }
        return dp1;
    }
};

// Problem: Number of Ways to Reach a Score
// LeetCode: https://leetcode.com/problems/number-of-ways-to-reach-a-score/

  vector<int> dp(n + 1);
    dp[0] = 1; // base case

    for (int i = 1; i <= n; ++i) {
        for (int dice = 1; dice <= 6; ++dice) {
            if (i - dice >= 0) {
                dp[i] = (dp[i] + dp[i - dice]) % MOD;
            }
        }
    }

// Problem: Word Break
// LeetCode: https://leetcode.com/problems/word-break/

    class Solution {
    public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[s.size()] = true;

        for (int i = s.size() - 1; i >= 0; i--) {
            for (const auto& w : wordDict) {
                if ((i + w.size()) <= s.size() && 
                     s.substr(i, w.size()) == w) {
                    dp[i] = dp[i + w.size()];
                }
                if (dp[i]) {
                    break;
                }
            }
        }

        return dp[0];
    }
};


//Problem: Maximum Product Subarray
// LeetCode: https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curMin = 1, curMax = 1;

        for (int num : nums) {
            int tmp = curMax * num;
            curMax = max(max(num * curMax, num * curMin), num);
            curMin = min(min(tmp, num * curMin), num);
            res = max(res, curMax);
        }
        return res;
    }
};

// Problem: Unique Paths
// LeetCode: https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> row(n, 1);

        for (int i = 0; i < m - 1; ++i) {
            vector<int> newRow(n, 1);
            for (int j = n - 2; j >= 0; --j) {
                newRow[j] = newRow[j + 1] + row[j];
            }
            row = newRow;
        }
        return row[0];
    }
};

// Problem: Jump Game
// LeetCode: https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= goal) {
                goal = i;
            }
        }

        return goal == 0;
    }
};
