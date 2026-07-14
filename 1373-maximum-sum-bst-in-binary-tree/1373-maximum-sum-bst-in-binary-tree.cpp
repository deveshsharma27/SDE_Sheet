/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <bits/stdc++.h>

class NodeValue {
public:
    int maxNode, minNode, sum;
    NodeValue(int maxNode, int minNode, int sum) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->sum = sum;
    };
};
class Solution {
private:
    int maxSum = 0;
    NodeValue helper(TreeNode* root) {
        // base case
        if (!root) {
            return NodeValue(INT_MIN, INT_MAX, 0);
        }

        auto left = helper(root->left);
        auto right = helper(root->right);

        // Check BST condition
        if (left.maxNode < root->val && root->val < right.minNode) {
            // It is a BST
            int currSum = left.sum + right.sum + root->val;
            maxSum = max(maxSum, currSum);
            return NodeValue(max(root->val, right.maxNode), // maxNode
                             min(root->val, left.minNode),  // minNode
                             currSum);
        }
        // Not a BST → invalidate
        return NodeValue(INT_MAX, INT_MIN, 0);
    }

public:
    int maxSumBST(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};