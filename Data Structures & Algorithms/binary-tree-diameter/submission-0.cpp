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
    int calculate(TreeNode *root,int &diameter){
         if(root==nullptr){
            return 0;

        }
        //we will calculate the  height of the left and the right 
        int leftheight=calculate(root->left,diameter);
        int rightheight=calculate(root->right,diameter);

        diameter=max(diameter,leftheight+rightheight);

         return max(leftheight,rightheight)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        int diameter=0;
       calculate(root,diameter);

    return diameter;
    }
};