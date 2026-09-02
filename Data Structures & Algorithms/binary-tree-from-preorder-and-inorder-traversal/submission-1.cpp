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
TreeNode * build(vector<int> &preorder,int &preindex,int start,int end,unordered_map<int,int>&in_map){
    if(start>end){
        return nullptr;
    }
    int rootval=preorder[preindex];
    preindex++;
    TreeNode *root=new TreeNode(rootval);
    //now the value from the left 
    int mid=in_map[rootval];
    root->left=build(preorder,preindex,start,mid-1,in_map);
    root->right=build(preorder,preindex,mid+1,end,in_map);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // as we have a preordertraversal first value is the root node and from the inordertraveesaal all the value from the left are left nodes and all to the right are right nodes
        unordered_map<int,int>in_map;
        for(int i =0;i<inorder.size();i++){
            in_map[inorder[i]]=i;
        }
        int preindex=0;
    return    build(preorder,preindex,0,inorder.size()-1,in_map);

    }
};
