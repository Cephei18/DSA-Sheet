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

// Problem: Delete Node in a BST
// LeetCode: https://leetcode.com/problems/delete-node-in-a-bst/

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        // Step 1: Traverse to find the node
        if (key < root->val_) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val_) {
            root->right = deleteNode(root->right, key);
        } else {
            // Found the node to delete

            // Case 1: No child
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }

            // Case 2: One child
            else if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Two children
            TreeNode* successor = findMin(root->right);
            root->val_ = successor->val_;  // Copy value
            root->right = deleteNode(root->right, successor->val_);  // Delete the duplicate
        }

        return root;
    }

private:
    TreeNode* findMin(TreeNode* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }
};
