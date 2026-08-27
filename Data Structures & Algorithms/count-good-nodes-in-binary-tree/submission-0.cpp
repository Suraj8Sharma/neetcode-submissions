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
int countnodes=0;
    int givecount(TreeNode *root,int largest){
        if(root==nullptr){
            return 0 ;
        }
        largest=max(largest,root->val);
        if(root->val>=largest){
            countnodes++;
        }
        givecount(root->left,largest);
      
        givecount(root->right,largest);
        return 0;
    }
    int goodNodes(TreeNode* root) {
     
        //root is always  a good noof
        givecount(root,root->val);
    return countnodes;
    }
};
