/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool checkBST(TreeNode* root,TreeNode *min_value,TreeNode * max_value) {
        if(root==nullptr){
            return true;
        }
        if (min_value!= nullptr && root->val<=min_value->val) {
            return false;
        }
           if (max_value!= nullptr && root->val>=max_value->val) {
            return false;
        }

        //now for left subtree the minimum stays -ifinitty to max values equal toparent 
      return   checkBST(root->left,min_value,root)&&
        checkBST(root->right,root,max_value);
    }
    bool isValidBST(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            return true;
        }
        return checkBST(root,nullptr,nullptr);
    }
};