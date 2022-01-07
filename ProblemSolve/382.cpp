/***************************
 * Linked List Random Node *
 ***************************/

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

//참고 : https://trancekim.tistory.com/3

class Solution {
public:
    ListNode* head;
        
    Solution(ListNode* head) {
        this -> head = head;
    }
    
    int getRandom() {
        float idx = 2.0f;
        float selectedProb = 0.5f;
        int returnValue = head -> val;
        
        ListNode* pointer = head -> next;
        
        
        while(pointer != NULL){
            if((float)(rand())/((float)(RAND_MAX)) < selectedProb){
                returnValue = pointer -> val;
            }
            
            selectedProb *= (idx++ / idx);
            idx++;
            pointer = pointer -> next;
        }
        
        return returnValue;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */