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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      //this is  easy just make a diiference of n and then move 
     if(head->next ==nullptr){
        return nullptr;
     }

     ListNode * dummy=new ListNode(0);
     
     dummy->next=head;
     ListNode * slow=dummy;
     ListNode * fast=head;
     for(int i =0;i<n;i++){
        fast=fast->next;
     }
     //now i have the differnnec of n between the 2 nodes so by the time the fast will be at the end node my previous poinyer will be at the previous 
   
     while( fast!=nullptr ){
        slow=slow->next;
        fast=fast->next;
     }
     slow->next=slow->next->next;
    
    return dummy->next;}
};
