/*******************
 * Add Two Numbers *
 *******************/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* temp = new ListNode(0);
        ListNode* temp2 = temp;
        
        //한 자리씩 확인하면서 더하고, 새로운 Linked List에 한 자리씩 추가
        //carry는 항상 0 아니면 1이기 때문에 carry도 while문의 조건으로 추가
        // 두 Linked List가 NULL이어도 carry가 남아있으면 carry를 추가할 수 있음
        while(carry || l1 != NULL || l2 != NULL){
            if(l1 != NULL){
                carry += l1 -> val;
                l1 = l1 -> next;
            }
            
            if(l2 != NULL){
                carry += l2 -> val;
                l2 = l2 -> next;
            }
            
            temp2 -> next = new ListNode(carry % 10);
            temp2 = temp2 -> next;
            carry = carry/10;
        }
        
        return temp -> next;
    }
};