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
class Solution {
public:
    bool isMirror(TreeNode* node1, TreeNode* node2){
// If both sides are null at the same time, return True because we reach the end of a    tree.
        if(node1==NULL && node2==NULL) return true;

//If one of sides is null, return False because it's not symmetric.        
        if(node1==NULL || node2==NULL) return false;


//Every time we have to compare two nodes from both sides.

       return node1->val == node2->val && isMirror(node1->left, node2->right) && isMirror(node1->right , node2->left);

    }
    bool isSymmetric(TreeNode* root) {
       // we should go left side and right side at the same time ---
       return isMirror(root->left, root->right);

    }
};