// bits.cpp
#include<bits/stdc++.h>
using namespace std;

// Problem: Number of 1 Bits
// LeetCode: https://leetcode.com/problems/number-of-1-bits/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            n &= n - 1;
            res++;
        }
        return res;
    }
};

// Problem: Counting Bits
// LeetCode: https://leetcode.com/problems/counting-bits/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            bits[i] = bits[i >> 1] + (i & 1);
        }
        return bits;
    }
};

// Problem: Reverse Bits
// LeetCode: https://leetcode.com/problems/reverse-bits/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            uint32_t bit = (n >> i) & 1;
            res += (bit << (31 - i));
        }
        return res;
    }
};

// Problem: Missing Number
// LeetCode: https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xorr = n;  
        for (int i = 0; i < n; i++) {
            xorr ^= i ^ nums[i];
        }
        return xorr;
    }
};

// Problem: Sum of Two Integers
// LeetCode: https://leetcode.com/problems/sum-of-two-integers/

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int carry = (a & b) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};