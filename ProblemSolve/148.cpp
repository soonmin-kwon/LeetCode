/*************
 * Sort List *
 *************/

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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        
        ListNode* secondHalf = getSecondHalf(head);         // Split. 뒤의 절반을 구함.
        ListNode* left = sortList(head);                    // 앞의 절반을 또 Split
        ListNode* right = sortList(secondHalf);             // 뒤의 절반을 또 Split
        
        return merge(left, right);                          //MergeSort 가장 작은 단위부터 Sorting이 
    }
    
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* pointer = new ListNode();
        ListNode* mergedList = pointer;
        while(left != NULL && right != NULL){
            if(left -> val > right -> val){
                pointer -> next = right;
                right = right -> next;
            }
            else{
                pointer -> next = left;
                left = left -> next;
            }
            pointer = pointer -> next;
        }
        
        if(left != NULL){
            pointer -> next = left;
        }
        else{
            pointer -> next = right;
        }
        
        return mergedList -> next;
    }
    
    ListNode* getSecondHalf(ListNode* head){
        ListNode* tortoise = head;
        ListNode* hare = head -> next -> next;
        
        while(hare != NULL && hare -> next != NULL){
            tortoise = tortoise -> next;
            hare = hare -> next -> next;
        }
        
        ListNode* secondHalf = tortoise -> next;
        tortoise -> next = NULL;
        return secondHalf;        
    }
};