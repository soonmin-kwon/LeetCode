/**************************
 * Merge Two Sorted Lists *
 **************************/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //합칠 게 없으면 리턴
        if(l1 == nullptr) {
          return l2;  
        } 
        
        if(l2 == NULL) {
            return l1;
        }
        
        //차례대로 next의 값을 선택하기 위해 재귀함수 사용
        //l2의 value가 더 크면 l1의 현재 값을 유지        
        if(l1-> val <= l2 -> val) {
            l1-> next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        //l1의 value가 더 크면 l2의 값으로 유지
        else {
            l2 -> next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }   
};