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
    void recursiveRightSideView(TreeNode* root, vector<int>&ds, int level){
       //preorder-> root, right, left (modified)
       if(root==NULL) return;

       if(level== ds.size()) ds.push_back(root->val);
       recursiveRightSideView(root->right,ds,level+1);
       recursiveRightSideView(root->left,ds,level+1 );
    }

    //Method--2->level order ->last node is indeed right view
     void levelOrder(TreeNode* root , vector<vector<int>>&ds){
        if(root==NULL) return ;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>level;

            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }
            ds.push_back(level);
        }
     }
    vector<int> rightSideView(TreeNode* root) {
        //   vector<int>ds;
        //   recursiveRightSideView(root, ds, 0);
        //   return ds;


        //-----------level order--------------
        
        vector<vector<int>>ds;
        levelOrder(root, ds);
         vector<int>res;
        for(auto &it:ds){
           res.push_back(it.back());
        }
       return res;
    }
};