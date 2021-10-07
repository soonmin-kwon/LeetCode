/***********************
 * Swap Nodes in Pairs *
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
    //현재 노드와 다음 노드를 스왑한다
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        
        ListNode* temp;
        //다음 노드에 연결된 리스트 저장
        temp = head -> next;
        
        //재귀적으로 들어가 제일 뒤에서부터 스왑한다
        //제일 뒤에서부터 바꿔야 최종적으로 모두 바뀐 리스트가 된다
        //짝수번째 노드와 홀수번째 노드를 바꿔야한다. ex) 1 -> 2 -> 3 -> 4 => (2 -> 1) -> (4 -> 3)
        head -> next = swapPairs(head -> next -> next);
        
        //현재 노드를 다음 노드로, 다음 노드를 현재 노드로 바꾼다
        temp -> next = head;
        
        return temp;
    }
};