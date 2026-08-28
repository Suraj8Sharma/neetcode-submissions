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
   
    void inorder(TreeNode * root,vector<int> & traversal_tree){
        //now i am travelling in order to get the sorted array
        if(root==nullptr){
            return ;
        }
        inorder(root->left,traversal_tree);
        traversal_tree.push_back(root->val);
        inorder(root->right,traversal_tree);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> traversal_tree;
        inorder(root,traversal_tree);
      
        return traversal_tree[k-1];
        
    }
};
