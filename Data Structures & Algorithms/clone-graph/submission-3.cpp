/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
Node *dfs(unordered_map<Node*,Node*>&mp,Node*node){
Node *clone=new Node(node->val);
mp[node]=clone;
vector<Node*>neighbours;
//i will seee the adjavceny list 
for(auto i:node->neighbors){
    if(mp.contains(i)){
        neighbours.push_back(mp[i]);
    }else{
        neighbours.push_back(dfs(mp,i));
    }

}
clone->neighbors=neighbours;
return clone;

}
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*>mp;

        if(node==nullptr){
            return nullptr;
        }
        if(node->neighbors.size()==0){
            Node *clone=new Node(node->val);
            return clone;
        }
        return dfs(mp,node);
    }
};
