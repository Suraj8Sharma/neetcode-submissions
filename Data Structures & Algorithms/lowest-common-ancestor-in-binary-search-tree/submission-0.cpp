/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {  
        if(root==nullptr){
            return nullptr;
        }
        if(root==p ||  root==q){
            return root;//basicaly eske niche he hoga dusra toh answer is thte root 
        }
       TreeNode * leftLCA= lowestCommonAncestor(root->left,p,q);
       TreeNode * RightLCA= lowestCommonAncestor(root->right,p,q);
      
        if (leftLCA!=nullptr && RightLCA!=nullptr){
        return root;
       }else  if(leftLCA!=nullptr){
        return leftLCA;
       }else {
        return  RightLCA;
       }
       
    }
};