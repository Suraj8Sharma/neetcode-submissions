class TrieNode{
public:
bool isCompleteWord=false;
TrieNode* children[26]={};
TrieNode()=default;
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root=new TrieNode();
    }
    
   bool dfs(string &word,int index,TrieNode *node){
    if(index==word.size()){

        return node->isCompleteWord;
    }
    char ch=word[index];
    if(ch=='.'){
        //it can match to any so need to check  across all 
        for(int  i=0;i<26;i++){
            if(node->children[i]!=nullptr){
                if(dfs(word,index+1,node->children[i])){
                    return true;
                }
            }
        }
        return false;
    }
    int idx=ch-'a';
    if(node->children[idx]==nullptr){
        return false;
    }
return dfs(word,index+1,node->children[idx]);
   }
    void addWord(string word) {
        TrieNode * node=root;
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
       return dfs(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */