/***********************************
 * Swapping Nodes in a Linked List *
 ***********************************/

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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* pointer1 = head, *pointer2 = head, *kthNode = NULL;
        
        while(k-- > 1){
            pointer1 = pointer1 -> next;
        }
        
        kthNode = pointer1;
        pointer1 = pointer1 -> next;
        
        //length = n이라할 때, kthNode는 k-1번째 Node
        //pointer1 = k번째 Node, n-k번째 Node를 찾기위해
        //n-k만큼 포인터를 옮기는데, pointer1을 끝까지 옮기면 n-k번만큼 옮길 수 있음.
        while(pointer1 != NULL){
            pointer1 = pointer1 -> next;
            pointer2 = pointer2 -> next;
        }
        
        swap(pointer2 -> val, kthNode -> val);
        
        return head;
    }
};