class TrieNode{
    public:
   bool isCompleteWord = false;
    TrieNode* children[26] = {}; // Zero-initializes all 26 pointers to nullptr

    TrieNode() = default; // No memset needed!

};
class PrefixTree {
public:
    TrieNode *root;
    PrefixTree() {
   root=new TrieNode();

    }
    
    void insert(string word) {
        TrieNode *node=root;
        for(char ch:word){
            int idx=ch-'a';
            if(node->children[idx]==nullptr){
                node->children[idx]=new TrieNode();
            }
            node=node->children[idx];
        }
        node->isCompleteWord=true;
    }
    
    bool search(string word) {
        
        TrieNode *node=root;
        for(char ch:word){
            int idx=ch-'a';
            if(node->children[idx]==nullptr){
                return false;
            }
            node=node->children[idx];
        }
        return  node->isCompleteWord;
    }
    
    bool startsWith(string prefix) {
        
        TrieNode *node=root;
        for(char ch:prefix){
            int idx=ch-'a';
            if(node->children[idx]==nullptr){
                return false;
            }
            node=node->children[idx];
        }
        return  true;
    
    }
};
