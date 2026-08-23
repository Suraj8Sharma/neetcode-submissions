class  Node{
public:
int key ;
int value;
Node *prev;
Node *next;

Node(int k,int v){
    key=k;
    value=v;
    prev=nullptr;
    next=nullptr;
}
}
;



class LRUCache {
    int cap;
    unordered_map<int,Node*>cache;
    Node *left;//es pointer ke sath mere most least used 
    Node *right;//ye right side ha es side most recently used hoge

    //making two helper function for making the insert and removal thing easy
    void removenode(Node * node){
        Node *prevnode=node->prev;
        Node *nextnode=node->next;
        prevnode->next=nextnode;
        nextnode->prev=prevnode;
    }

    void insertnode(Node *node){
        Node  *prevnode=right->prev;
        Node *nextnode=right;
        prevnode->next=node;
        nextnode->prev=node;
        node->next=nextnode;
        node->prev=prevnode;
    }
public:
    LRUCache(int capacity) {
        cap=capacity;
        //setting up dummy node
        left = new Node(0,0);
        right= new Node(0,0);
        

        left->next=right;
        right->prev=left;
    }
    
    int get(int key) {
        //if the key exists 
        if(cache.contains(key)){
            Node *  node=cache[key];
            removenode(node);
            insertnode(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
       if(cache.contains(key)){
        Node *node=cache[key];
        removenode(node);
        node->value=value;
        insertnode(node);
        return ;
       }
       Node *newnode= new Node(key,value);
        cache[key]=newnode;
        insertnode(newnode);
       if(cache.size()>cap){  
        Node* lru = left->next;
        removenode(lru);
        cache.erase(lru->key);
        delete lru;
       }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */