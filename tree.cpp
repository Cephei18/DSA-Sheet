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

// Problem: Invert Binary Tree
// LeetCode: https://leetcode.com/problems/invert-binary-tree/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return nullptr;

        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);

        return root;

    }
};

// Problem: Maximum Depth of Binary Tree
// LeetCode: https://leetcode.com/problems/maximum-depth-of-binary-tree/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root){
            return 0;
        }
        return 1+ max(maxDepth(root->left),maxDepth(root->right));
    }
};

// Problem: Same Tree
// LeetCode: https://leetcode.com/problems/same-tree/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;

        if(p && q && p->val_ == q->val_){
            return isSameTree(p->left,q->left) && 
             isSameTree(p->right,q->right) ;
        }
        else{ return false;}
        
    }
};

// Problem: Subtree of Another Tree
// LeetCode: https://leetcode.com/problems/subtree-of-another-tree/

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) {
            return true;
        }
        if (!root) {
            return false;
        }

        if (sameTree(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) || 
               isSubtree(root->right, subRoot);
    }

    bool sameTree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) {
            return true;
        }
        if (root && subRoot && root->val_ == subRoot->val_) {
            return sameTree(root->left, subRoot->left) &&
                   sameTree(root->right, subRoot->right);
        }
        return false;
    }
};