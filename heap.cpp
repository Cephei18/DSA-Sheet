#include <bits/stdc++.h>
using namespace std;

// Problem: Top K Frequent Elements
// LeetCode: https://leetcode.com/problems/top-k-frequent-elements/


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for (auto& entry : count) {
            heap.push({entry.second, entry.first});
            if (heap.size() > k) {
                heap.pop();
            }
        }

        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};

/// Problem: Top K Frequent Elements (Alternative Approach)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);

        for (int n : nums) {
            count[n] = 1 + count[n];
        }
        for (const auto& entry : count) {
            freq[entry.second].push_back(entry.first);
        }

        vector<int> res;
        for (int i = freq.size() - 1; i > 0; --i) {
            for (int n : freq[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};

// Problem: Top K Frequent Elements (Using Bucket Sort Approach)
// LeetCode: https://leetcode.com/problems/top-k-frequent-elements/


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int n : nums) {
            count[n]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for (const auto& entry : count) {
            buckets[entry.second].push_back(entry.first);
        }

        vector<int> res;
        for (int i = buckets.size() - 1; i >= 0 && res.size() < k; --i) {
            for (int n : buckets[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};

// Problem: Kth Largest Element in a Stream
// LeetCode: https://leetcode.com/problems/kth-largest-element-in-a-stream/

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }

    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};

// Problem: Last Stone Weight
// LeetCode: https://leetcode.com/problems/last-stone-weight/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxHeap;

        for(int stone:stones){
            maxHeap.push(stone);
        }

        while(maxHeap.size()>1){
            int stone1 = maxHeap.top();
            maxHeap.pop();

            int stone2 = maxHeap.top();
            maxHeap.pop();

            if(stone1 != stone2){
                maxHeap.push(stone1-stone2);
            }
        }
        if(maxHeap.empty()) return 0;
        else {
           return maxHeap.top();
        }

    }
};

// Problem: Find Median from Data Stream
// LeetCode: https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {

private:
        priority_queue<int>maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap; 

public:
    MedianFinder() {}
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if(minHeap.size()>maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
    if (maxHeap.size() == minHeap.size()) {
        return (maxHeap.top() + minHeap.top()) / 2.0;
    } 
    else {
        return maxHeap.top();
    }
}
};

// Problem: Meeting Rooms II
// LeetCode: https://leetcode.com/problems/meeting-rooms-ii/

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a.start < b.start;
        });
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (const auto& interval : intervals) {
            if (!minHeap.empty() && minHeap.top() <= interval.start) {
                minHeap.pop();
            }
            minHeap.push(interval.end);
        }
        return minHeap.size();
    }
};