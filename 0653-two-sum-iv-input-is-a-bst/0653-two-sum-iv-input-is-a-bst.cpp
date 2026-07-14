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
//inorder is already sorted --
    void inorder(TreeNode* root, vector<int>&arr){
        if(root==NULL) return;

        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    bool findTarget(TreeNode* root, int k) {
       if(root == NULL ) return false;
       vector<int>ans;
       inorder(root, ans); 


       int left =0 , right = ans.size()-1;

       while(left< right){
        if(ans[left]+ans[right] == k){
            return true;
        }
        else if(ans[left] +  ans[right] > k){
            right--;
        }else{
            left++;
        }
       }

       return false;
    }
};