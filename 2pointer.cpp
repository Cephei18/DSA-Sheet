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


// Problem: 3Sum
// LeetCode: https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for (int i = 0; i < n - 2; ++i) {
            // Skip duplicates
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    // Skip duplicates
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;
    }
};


// Problem: Valid Palindrome
// LeetCode: https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        // Convert to lowercase
        for (char& c : s) {
            c = tolower(c);
        }

        // Remove non-alphanumeric characters
        s.erase(remove_if(s.begin(), s.end(), [](char c) {
            return !isalnum(static_cast<unsigned char>(c));
        }), s.end());

        // Two-pointer check for palindrome
        int i = 0;
        int j = s.length() - 1;

        while (i <= j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }
};

// Problem: Container With Most Water
// LeetCode: https://leetcode.com/problems/container-with-most-water/


class Solution {
public:
    int maxArea(vector<int>& heights) {
         
        int l = 0;
        int r = heights.size()-1;
        int maxA = 0;
        while(l<r){
         int area = (r-l) * min(heights[l],heights[r]);
         maxA = max(area,maxA);
           if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maxA;

    }
};

// Problem: Trapping Rain Water
// LeetCode: https://leetcode.com/problems/trapping-rain-water/


class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        int l = 0, r = height.size() - 1;
        int leftMax = height[l], rightMax = height[r];
        int res = 0;
        while (l < r) {
            if (leftMax < rightMax) {
                l++;
                leftMax = max(leftMax, height[l]);
                res += leftMax - height[l];
            } else {
                r--;
                rightMax = max(rightMax, height[r]);
                res += rightMax - height[r];
            }
        }
        return res;
    }
};

// Problem: Best Time to Buy and Sell Stock
// LeetCode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0;
        int r=1;
        int maxP = 0;
        while(r<prices.size()){
            if(prices[l]<prices[r]){
                int profit = prices[r]-prices[l];
                maxP = max(maxP,profit);
            }
            else{l=r;}
            r++;
        }
        return maxP;
    }
};

// Problem: Longest Substring Without Repeating Characters
// LeetCode: https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int l = 0;
        int res = 0;

        for (int r = 0; r < s.size(); r++) {
            while (charSet.find(s[r]) != charSet.end()) {
                charSet.erase(s[l]);
                l++;
            }
            charSet.insert(s[r]);
            res = max(res, r - l + 1);
        }
        return res;
    }
};

// Problem: Remove Duplicates from Sorted Array
// LeetCode: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0;
        while (r < n) {
            nums[l] = nums[r];
            while (r < n && nums[r] == nums[l]) {
                r++;
            }
            l++;
        }
        return l;
    }
};

// Problem: Remove Duplicates from Sorted Array II
// LeetCode: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;  // insert position
        for (int n : nums) {
            if (i < 2 || n != nums[i - 2]) {
                nums[i++] = n;
            }
        }
        return i;
    }
};

//Problem: Contains Duplicate II
// LeetCode: https://leetcode.com/problems/contains-duplicate-ii/

bool closeDuplicates(vector<int>& nums, int k) {
    unordered_set<int> window; // Cur window of size <= k
    int L = 0;

    for (int R = 0; R < nums.size(); R++) {
        if (R - L + 1 > k+1) {
            window.erase(nums[L]);
            L++;
        }
        if (window.count(nums[R]) > 0) {
            return true;
        }
        window.insert(nums[R]);
    }
    return false;
}

// Problem: Number of Subarrays of Size K and Average Greater than or Equal to Threshold
// LeetCode: https://leetcode.com/problems/number-of-subarrays-of-size-k-and

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans = 0;
        int sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            if (i >= k) {
                sum -= arr[i - k];
            }

            if (i >= k - 1) {
                if (sum / k >= threshold) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

// Problem: Minimum Size Subarray Sum
// LeetCode: https://leetcode.com/problems/minimum-size-subarray-sum/   

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minL = INT_MAX;
        int sum = 0;
        int l = 0;

        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];

            while (sum >= target) {
                minL = min(minL, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }

        return (minL == INT_MAX) ? 0 : minL;
    }
};

// Problem: Maximum Subarray
// LeetCode: https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub = nums[0], curSum = 0;
        for (int num : nums) {
            if (curSum < 0) {
                curSum = 0;
            }
            curSum += num;
            maxSub = max(maxSub, curSum);
        }
        return maxSub;
    }
};

// Problem: Minimum Window Substring
// LeetCode: https://leetcode.com/problems/minimum-window-substring/


class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> countT, window;
        for (char c : t) {
            countT[c]++;
        }

        int have = 0, need = countT.size();
        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;
        int l = 0;

        for (int r = 0; r < s.length(); r++) {
            char c = s[r];
            window[c]++;

            if (countT.count(c) && window[c] == countT[c]) {
                have++;
            }

            while (have == need) {
                if ((r - l + 1) < resLen) {
                    resLen = r - l + 1;
                    res = {l, r};
                }

                window[s[l]]--;
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};

// Problem: Longest Palindromic Substring
// LeetCode: https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
        int resIdx = 0;
        int resLen = 0;
        //ODD
        for(int i=0;i<s.size();i++){
           int l=i ;
           int r = i;
           while(l>=0 && r<s.size() && s[l]==s[r]){
            if(r-l+1 > resLen){
                resIdx = l;
                resLen = r-l+1;
            }
            l--;
            r++;
           }

           //EVEN
           l = i;
           r = i+1;
           while(l>=0 && r<s.size() && s[l]==s[r]){
            if(r-l+1 > resLen){
                resIdx = l;
                resLen = r-l+1;
            }
            l--;
            r++;
           }
           
    }
    return s.substr(resIdx,resLen);
    }
};

// Problem: Longest Increasing Subsequence
// LeetCode: https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);

        int LIS =1;
        for(int i=1;i<nums.size();i++){
            if(dp.back()<nums[i]){
                dp.push_back(nums[i]);
                LIS++;
                continue;
            }

            int idx = lower_bound(
                dp.begin(), dp.end(), nums[i] ) - dp.begin();
            dp[idx] = nums[i];
        }
        return LIS;
    }
};

// Problem: Minimum Window Substring
// LeetCode: https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> countT, window;
        for (char c : t) {
            countT[c]++;
        }

        int have = 0, need = countT.size();
        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;
        int l = 0;

        for (int r = 0; r < s.length(); r++) {
            char c = s[r];
            window[c]++;

            if (countT.count(c) && window[c] == countT[c]) {
                have++;
            }

            while (have == need) {
                if ((r - l + 1) < resLen) {
                    resLen = r - l + 1;
                    res = {l, r};
                }

                window[s[l]]--;
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};

// Problem: 4Sum
// LeetCode: https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end()); // Important to handle duplicates

        for (int i = 0; i < n - 3; i++) {
            // Skip duplicate nums[i]
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++) {
                // Skip duplicate nums[j]
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int l = j + 1;
                int r = n - 1;

                while (l < r) {
                    long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];

                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;

                        // Skip duplicates for l and r
                        while (l < r && nums[l] == nums[l - 1]) l++;
                        while (l < r && nums[r] == nums[r + 1]) r--;
                    }
                    else if (sum < target) {
                        l++;
                    }
                    else {
                        r--;
                    }
                }
            }
        }

        return ans;
    }
};

// Best Time to Buy and Sell Stock
// LeetCode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int l = 0; // buy day

        for (int r = 1; r < prices.size(); r++) {
            if (prices[r] < prices[l]) {
                l = r; // found cheaper buy day
            } else {
                maxprofit = max(maxprofit, prices[r] - prices[l]);
            }
        }
        return maxprofit;
    }
};

// Problem: Number of Subarrays of Size K and Average Greater than or Equal to Threshold
// LeetCode: https://leetcode.com/problems/number-of-subarrays-of-size-k-and-average-greater-than-or-equal-to-threshold/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int ans = 0;
        int sum = 0;

        // First window
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        if (sum / k >= threshold) ans++;

        // Slide the window
        for (int i = k; i < n; i++) {
            sum += arr[i];        // add new element
            sum -= arr[i - k];    // remove leftmost
            if (sum / k >= threshold) ans++;
        }

        return ans;
    }
// permutation in string
// https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);
        for (int i = 0; i < s1.length(); i++) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (s1Count[i] == s2Count[i]) {
                matches++;
            }
        }

        int l = 0;
        for (int r = s1.length(); r < s2.length(); r++) {
            if (matches == 26) {
                return true;
            }

            int index = s2[r] - 'a';
            s2Count[index]++;
            if (s1Count[index] == s2Count[index]) {
                matches++;
            } else if (s1Count[index] + 1 == s2Count[index]) {
                matches--;
            }

            index = s2[l] - 'a';
            s2Count[index]--;
            if (s1Count[index] == s2Count[index]) {
                matches++;
            } else if (s1Count[index] - 1 == s2Count[index]) {
                matches--;
            }
            l++;
        }
        return matches == 26;
    }
};

// 3Sum
// LeetCode: https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > 0) {
                    r--;
                } else if (sum < 0) {
                    l++;
                } else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                }
            }
        }
        return res;
    }
};

// Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        int resLen = 0, resIdx = 0;

        for (int i = 0; i < s.size(); i++) {
            // odd length
            int l = i, r = i;
            while (l >= 0 && r < s.size() &&
                   s[l] == s[r]) {
                if (r - l + 1 > resLen) {
                    resIdx = l;
                    resLen = r - l + 1;
                }
                l--;
                r++;
            }

            // even length
            l = i;
            r = i + 1;
            while (l >= 0 && r < s.size() &&
                   s[l] == s[r]) {
                if (r - l + 1 > resLen) {
                    resIdx = l;
                    resLen = r - l + 1;
                }
                l--;
                r++;
            }
        }

        return s.substr(resIdx, resLen);
    }
};