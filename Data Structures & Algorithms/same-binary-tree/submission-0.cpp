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
    bool compare(TreeNode *node1,TreeNode *node2){
        if(node1==nullptr && node2==nullptr){
            return true;
        }
        if(node1==nullptr ){
            return false;
        }
        if(node2==nullptr){
            return false;
        }
        if(node1->val==node2->val){
         return    compare(node1->left,node2->left) && compare(node1->right,node2->right);
        }
            return false;
        
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr  && q==nullptr){
            return true;
        }
        if(p==nullptr){
            return false;
        }
        if(q==nullptr){
            return false;
        }
        if(p->val!=q->val){
            return false;
        }
        return compare(p->left,q->left) &&compare(p->right,q->right);
    }
};