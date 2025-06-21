#include<bits/stdc++.h>
using namespace std;


class TreeNode {
    public:
        int val_;
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;

        TreeNode(int val) {
            val_ = val;
        }
};

// Problem: Search in a Binary Search Tree
// LeetCode: https://leetcode.com/problems/search-in-a-binary-search-tree/


bool search(TreeNode* root, int target) {
    if (!root) {
        return false;
    }

    if (target > root->val_) {
        return search(root->right, target);
    } else if (target < root->val_) {
        return search(root->left, target);
    } else {
        return true;
    }
}

// Problem: Insert into a Binary Search Tree
// LeetCode: https://leetcode.com/problems/insert-into-a-binary-search-tree/

// Insert a new node and return the root of the tree.
TreeNode* insert(TreeNode* root, int val) {
    if (!root) {
        return new TreeNode(val);
    }

    if (val > root->val_) { 
        root->right = insert(root->right, val);
    } else if (val < root->val_) {
        root->left = insert(root->left, val);
    }
    return root;
}

