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
int calculate(TreeNode *root){
    if(root==nullptr){
        return 0;
    }
    int leftheight=calculate(root->left);
    int rightheight=calculate(root->right);

    if(leftheight==-1){
        return -1;
    }
    if(rightheight==-1){
        return -1;
    }
    if(abs(leftheight-rightheight)>1){
        return -1;
    }
    return max(leftheight,rightheight)+1;
}
    bool isBalanced(TreeNode* root) {
        int check=calculate(root);
        if(check == -1){
            return false;
        }
        return true;
    }
};
