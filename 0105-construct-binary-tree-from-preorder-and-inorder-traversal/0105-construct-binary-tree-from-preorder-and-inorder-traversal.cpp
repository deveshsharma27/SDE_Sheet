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
public:TreeNode* buildTreePreIn(vector<int>& inorder,int is,int ie,vector<int>& preorder,int ps,int pe, map<int,int>&hm)

{

    if(is>ie|| ps>pe) return NULL;

    TreeNode* root=new TreeNode(preorder[ps]);

    long long  inRoot=hm[root->val]; // root element in INORDER array
long long  numsLeft=inRoot-is; //number left inoder array

    root->left=buildTreePreIn(inorder,is,inRoot-1,preorder,ps+1,ps+numsLeft,hm);
    root->right=buildTreePreIn(inorder,inRoot+1,ie,preorder,ps+numsLeft+1,pe,hm);

return root;

}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size()!=preorder.size())
        return NULL;

        map<int,int> hm;
        for(int i=0; i<inorder.size();i++){
            hm[inorder[i]]=i;// 3->1 {element->index}
            
        }
        return buildTreePreIn(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,hm);
         
    }
};