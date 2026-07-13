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
    void flatten(TreeNode* root) {
        if (root == NULL) return;
          //Morris preorder traversal -> O(n) sc->O(1)
          //recusrion (o(n)) sc->O(N)
          //stack ->(o(n)) sc->O(N)
        TreeNode* cur = root;

        while (cur != NULL) {
            if (cur->left != NULL) {

                // Find rightmost node of left subtree
                TreeNode* prev = cur->left;
                while (prev->right) {
                    prev = prev->right;
                }

                // Rewire connections
                prev->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }

            // Move to next node
            cur = cur->right;
        }
    }
};