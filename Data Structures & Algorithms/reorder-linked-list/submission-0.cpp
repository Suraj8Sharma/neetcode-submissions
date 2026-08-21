/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
      // the logic is gettig a little bit cleare what we have to do is to reorder the list so need to find the middle 
     ListNode * slow=head;
     ListNode * fast=head;
     while(fast->next !=nullptr && fast->next->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
     }

     //now the second is that i need to basically reverse the second half
     ListNode *prev=nullptr;
     ListNode *curr=slow->next;
     slow->next=nullptr;
     ListNode *next=curr;

     while(curr!=nullptr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
     }

     //so now  we have two lists prepared just needed to comibne 
     ListNode *temp1=head;
     ListNode * temp2=prev;
     while(temp1 !=nullptr && temp2 !=nullptr){
        ListNode  *first=temp1->next;
        ListNode *second=temp2->next;
    
        temp1->next=temp2;
        
        temp2->next=first;
        temp1=first;
        temp2=second;
     }
    
    }
};
