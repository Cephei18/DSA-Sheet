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


//Problem : Kruskal's Algorithm for Minimum Spanning Tree
// LeetCode: https://leetcode.com/problems/kruskals-algorithm-for-minimum-spanning-tree/
// Note: This implementation uses a Union-Find data structure to manage connected components.

class UnionFind {
public:
    vector<int> parent;
    vector<int> size;
    int numComponents;

    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        numComponents = n;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        // Finds the root of x
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union is a reserved keyword in C++, so we use _union instead
    bool _union(int x, int y) {
        // Connects x and y
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            } else {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }
            numComponents--;
            return true;
        }
        return false;
    }

    int getNumComponents() {
        return numComponents;
    }
};

class Solution {
public:
    // Implementation for Kruskal's algorithm to compute Minimum Spanning Trees
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        // Sort edges by weight using min heap
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap; 
        for (const auto& edge : edges) {
            minHeap.push(make_tuple(edge[2], edge[0], edge[1]));
        }

        UnionFind unionFind(n);
        int totalWeight = 0;
        while (!minHeap.empty()) {
            tuple<int, int, int> cur = minHeap.top();
            int w1 = std::get<0>(cur), n1 = std::get<1>(cur), n2 = std::get<2>(cur);
            minHeap.pop();

            if (unionFind._union(n1, n2)) {
                totalWeight += w1;
            }
        }
        // Return -1 if not all nodes are visited (unconnected graph)
        return unionFind.getNumComponents() != 1 ? -1 : totalWeight;
    }
};

// Problem: Last Stone Weight
// LeetCode: https://leetcode.com/problems/last-stone-weight/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> maxHeap(stones.begin(), stones.end());

        while (maxHeap.size() > 1) {
            int stone1 = maxHeap.top(); maxHeap.pop();
            int stone2 = maxHeap.top(); maxHeap.pop();

            if (stone1 != stone2) {
                maxHeap.push(stone1 - stone2);
            }
        }

        return maxHeap.empty() ? 0: maxHeap.top();
    }
};

// Problem: K Closest Points to Origin
// LeetCode: https://leetcode.com/problems/k-closest-points-to-origin/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // max-heap: store {distance, {x,y}}
        priority_queue<pair<int, vector<int>>> pq;

        for (auto& point : points) {
            int x = point[0], y = point[1];
            int dist = x*x + y*y;
            pq.push({dist, point});

            if (pq.size() > k) {
                pq.pop(); // remove farthest point
            }
        }

        // collect results
        vector<vector<int>> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};


// Problem: Kth Largest Element in an Array
// LeetCode: https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};