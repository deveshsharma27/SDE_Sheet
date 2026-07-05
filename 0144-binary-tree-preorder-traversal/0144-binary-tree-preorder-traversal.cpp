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
    void preorder(TreeNode* root , vector<int>&ans){
      if(root==NULL) return;

      ans.push_back(root->val);
      preorder(root->left,ans);
      preorder(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        // Morris preorder Traversal----Thread traversals--
        TreeNode* cur = root;
        vector<int> inorder;

        while (cur != NULL) {

            if (!cur->left) {
                inorder.push_back(cur->val);
                cur = cur->right;
            } else {
                TreeNode* prev = cur->left;

                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    prev->right = cur;
                    inorder.push_back(cur->val);
                    cur = cur->left;
                } else {
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return inorder;  
    }
};