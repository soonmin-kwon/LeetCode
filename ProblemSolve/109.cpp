/*********************************************
 * Convert Sroted List to Binary Search Tree *
 *********************************************/

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        
        if(head -> next == NULL){
            return new TreeNode(head -> val);
        }
        
        ListNode* tortoise = head;
        ListNode* hare = head -> next -> next;
        
        //Tortoise & Hare 알고리즘으로 범위에서 middle 값을 찾는다
        //위에서 hare를 head -> next -> next로 설정했기 때문에
        //tortoise 값은 middle값 이전 값이 된다
        while(hare != NULL && hare -> next != NULL){
            tortoise = tortoise -> next;
            hare = hare -> next -> next;
        }
                
        hare = tortoise -> next;    //middle 값, 현재 root
        tortoise -> next = NULL;    //tortoise -> next를 NULL로 만들어 head를 left 범위만큼만 남김
        tortoise = hare -> next;    //tortoise를 middle의 다음 값으로 설정해 right 범위 생성        
        
        return new TreeNode(hare -> val, sortedListToBST(head), sortedListToBST(tortoise));        
    }
};