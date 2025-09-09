#include<bits/stdc++.h>
using namespace std;


// Problem: Encode and Decode Strings
// LeetCode: https://leetcode.com/problems/encode-and-decode-strings/   

class Solution {
public:
    string encode(vector<string>& strs) {
        string res;
        for (const string& s : strs) {
            res += to_string(s.size()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            i = j + 1;
            j = i + length;
            res.push_back(s.substr(i, length));
            i = j;
        }
        return res;
    }
};


class Solution {
public:
    string countAndSay(int n) {
    string s = "1";  // base case
    for (int i = 2; i <= n; i++) {
        string result = "";
        int count = 1;
        for (int j = 1; j < s.size(); j++) {
            if (s[j] == s[j - 1]) {
                count++;  // same digit → increase count
            } else {
                // different digit → append "count + digit"
                result += to_string(count) + s[j - 1];
                count = 1;  // reset count
            }
        }
        // append the last run
        result += to_string(count) + s.back();
        s = result;
    }
    return s;
}
};