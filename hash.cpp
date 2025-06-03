#include <vector>
#include <unordered_set>    // For unordered_set
#include <iostream>
#include<bits/stdc++.h>
using namespace std;


// Function to check if there are any duplicate elements in the vector

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
   unordered_map<int,int> freq;

   for(int i:nums){
    freq[i]++;
   }
   for (auto& p : freq) {
     if (p.second > 1)
     return true;
   }
   return false;
}
};