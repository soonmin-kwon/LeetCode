/*********************
 * Linked List Cycle *
 *********************/

class Solution {
public:
    // Floyd's Tortoise & Hare Algorithm
    bool hasCycle(ListNode *head) {
        //토끼와 거북이를 설정
        ListNode* tortoise = head;
        ListNode* hare = head;
        
        if(head == NULL){
            return false;
        }
        
        //토끼를 빠르게 움직이고 거북이를 느리게 움직여서 만나면 사이클
        while(hare -> next && hare -> next -> next){
            tortoise = tortoise -> next;
            hare = hare -> next -> next;
            
            if(tortoise == hare){
                return true;
            }
        }
        
        return false;
    }
};