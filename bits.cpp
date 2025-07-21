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
