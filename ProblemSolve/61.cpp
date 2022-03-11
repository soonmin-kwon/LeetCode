/***************
 * Rotate List *
 ***************/

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
    ListNode* rotateRight(ListNode* head, int k) {
        int length = 1;
        
        ListNode* headFirst = head;
        
        if(head == NULL)
            return NULL;
        
        while(head -> next != NULL){
            head = head -> next;
            length++;
            
            if(head -> next == NULL){
                head -> next = headFirst;
                break;
            }
        }
        
        if(length == 1){
            return head;
        }
        
        length = length - (k % length);
        
        for(int i=0; i<length-1; ++i){
            headFirst = headFirst -> next;
        }
        
        ListNode* ans = headFirst -> next;
        headFirst -> next = NULL;
        
        return ans;
    }
};