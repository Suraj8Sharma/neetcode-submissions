/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return nullptr;
        }
        //so  basically approach is interweaving clone into the original 
        //previous a->b->c new a>a1>b>B1>C>C1
        Node *curr=head;
        while(curr){
            Node *clonednode=new Node(curr->val);
            clonednode->next=curr->next;
            curr->next=clonednode;
            curr=clonednode->next;
        }
        //part2 is the random pointers of cloned are to be assigned 
        curr=head;
        while(curr){
            if(curr->random){
                curr->next->random=curr->random->next;//bascially curr->random se  will at the old node so just next to it will be the new one
            }
            curr=curr->next->next;

        }
        //pass-3 separting the clones from the orginal
        curr=head;
        Node *clonedhead=curr->next;
        while(curr){
            Node * clonednode=curr->next;
            curr->next=clonednode->next;
            if (clonednode->next) {
                clonednode->next = clonednode->next->next; // Link cloned lis
            }
            curr=curr->next;
        }
   return clonedhead; }
};