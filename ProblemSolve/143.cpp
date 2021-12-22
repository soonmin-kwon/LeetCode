/****************
 * Reorder List *
 ****************/

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
        if(head == NULL || head -> next == NULL){
            return;
        }
        
        ListNode* firstHalf = head;
        ListNode* secondHalfReverse = head -> next;
        
        while(secondHalfReverse != NULL && secondHalfReverse -> next != NULL){
            firstHalf = firstHalf -> next;
            secondHalfReverse = secondHalfReverse -> next -> next;
        }
        
        ListNode* secondHalfTemp = firstHalf -> next;
        firstHalf -> next = NULL;
        
        secondHalfReverse = secondHalfTemp -> next;
        secondHalfTemp -> next = NULL;
        
        //Reverse
        while(secondHalfReverse != NULL){
            firstHalf = secondHalfReverse -> next;
            secondHalfReverse -> next = secondHalfTemp;
            secondHalfTemp = secondHalfReverse;
            secondHalfReverse = firstHalf;
        }
        
        firstHalf = head;
        secondHalfReverse = secondHalfTemp;
        
        //하나씩 연결
        //구슬 꿰듯이
        while(firstHalf != NULL){
            ListNode* temp = firstHalf -> next;
            firstHalf -> next = secondHalfReverse;
            firstHalf = firstHalf -> next;
            secondHalfReverse = temp;
        }
    }
};