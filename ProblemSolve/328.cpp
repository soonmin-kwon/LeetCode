/************************
 * Odd Even Linked List *
 ************************/

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        
        ListNode* oddList = head;
        ListNode* evenList = head -> next;
        ListNode* evenListHead = evenList;
        
        //odd은 1번째, even은 2번째 노드를 가리킨다고 하면
        //odd의 다음은 3번째가 되어야 하므로 even의 next
        //even의 다음은 4번째가 되어야 하므로 odd를 3번째로 옮기고 그 다음 걸 참조하면 됨.
        while(evenList != NULL && evenList -> next != NULL){
            oddList -> next = evenList -> next;
            oddList = oddList -> next;
            
            evenList -> next = oddList -> next;
            evenList = evenList -> next;
        }
        
        //이어 붙이기
        oddList -> next = evenListHead;
        
        return head;
    }
};