/*****************************************
 * Remove Duplicates from Sorted List II *
 *****************************************/

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ans = new ListNode(0, head);
        
        ListNode* ansPointer = ans;
        
        while(head != NULL){
            if(head -> next != NULL && head -> val == head -> next -> val){
                while(head -> next != NULL && head -> val == head -> next -> val){
                    head = head -> next;
                }
                
                ansPointer -> next = head -> next;
            }
            else{
                ansPointer = ansPointer -> next;
            }
            
            head = head -> next;
        }
        
        return ans -> next;
    }
};