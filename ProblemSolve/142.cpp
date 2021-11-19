/************************
 * Linked List Cycle II *
 ************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        
        //Tortoise & Hare Algorithm
        //사이클을 찾는 전형적인 알고리즘
        ListNode* tortoise = head->next;
        ListNode* hare = head->next->next;
        
        while(hare != NULL && hare -> next != NULL){
            tortoise = tortoise -> next;
            hare = hare -> next -> next;
            
            if(tortoise == hare){
                tortoise = head;
                
                while(tortoise != hare){
                    tortoise = tortoise -> next;
                    hare = hare -> next;
                }
                
                return tortoise;
            }
        }
        
        return NULL;
    }
};