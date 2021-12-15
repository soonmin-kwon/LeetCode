/***********************
 * Insertion Sort List *
 ***********************/

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* ans = new ListNode(0);
        
        while(head != NULL){
            ListNode* headPointer = head;
            ListNode* ansPointer = ans;
            head = head -> next;
            
            //들어갈 자리 찾기.
            while(ansPointer -> next != NULL && ansPointer -> next -> val < headPointer -> val){
                ansPointer = ansPointer -> next;
            }
            
            //사용한 node 삭제
            headPointer -> next = ansPointer -> next;
            ansPointer -> next = headPointer;
        }
        
        return ans -> next;
    }
};