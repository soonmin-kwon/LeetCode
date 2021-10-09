/******************************
 * Linked List in Binary Tree *
 ******************************/

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
    //현재 root부터 linked list가 path로 있는지 확인
    bool hasPathFromRoot(ListNode* head, TreeNode* root){
        //head가 null이면 linked list의 끝까지 도달했다는 뜻, path가 존재한다
        if(head == NULL){
            return true;
        }
        
        if(root == NULL){
            return false;
        }
        
        //linked list의 값과 root의 값이 다르면 현재 점에서 path가 있을 수 없다
        if(head -> val != root -> val){
            return false;
        }
        
        //현재 root와 head의 val이 같으면 정상적으로 진행한다.
        //head를 다음 node로 옮기고, root를 각각 left child와 right child로 진행한다
        return hasPathFromRoot(head -> next, root -> left) || hasPathFromRoot(head -> next, root -> right);
    }    
        
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root == NULL){
            return false;
        }
        
        //트리에 존재하는 모든 노드를 돌면서 모든 노드에서 path가 있을 수 있는지 확인한다
        return hasPathFromRoot(head, root) || isSubPath(head, root -> left) || isSubPath(head, root -> right);
    }
};