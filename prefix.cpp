#include<bits/stdc++.h>
using namespace std;   

// Problem: Product of Array Except Self
// LeetCode: https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        
        int postfix = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= postfix;
            postfix *= nums[i];
        }
        return res;
    }
};

// Problem: Longest Common Prefix
// LeetCode: https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

      string prefix = strs[0];
      for(int i=1;i<strs.size();i++){
        int j=0;
        while(j<min(prefix.length(),strs[i].length())){
            if(prefix[j] != strs[i][j]){
                break;
            }
            j++;
        }
        prefix = prefix.substr(0,j);
      }
      return prefix; 
    }
};