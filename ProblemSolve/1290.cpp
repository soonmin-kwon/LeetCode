/*****************************************************
 * Convert Binary Number in a Linked List to Integer *
 *****************************************************/

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
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        
        //한칸씩 left shift, 새로 들어온 비트 값 추가
        while(head != NULL){
            ans *= 2;
            ans += head -> val;
            head = head -> next;
        }
        
        return ans;
    }
};