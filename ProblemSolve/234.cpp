/**************************
 * Palindrome Linked List *
 **************************/

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        //현재 또는 다음이 NULL이면 리턴, 마지막 값을 포인터로 만든다.
        if(head == NULL || head -> next == NULL){
            return head;
        }
        
        ListNode* ans = reverse(head -> next);
        //다음 다음을 현재 node로 만들면 사이클이 생긴다. ex) 5 -> 4
        head -> next -> next = head;
        //다음 노드로 가는 연결을 끊으면 사이클이 없어진다.
        head -> next = NULL;
        
        return ans;
    }   
    
    bool isPalindrome(ListNode* head) {                
        ListNode* firstHalf = head;
        ListNode* secondHalf = head;
                
        //중간 지점으로 나눈다.
        while(firstHalf != NULL && firstHalf -> next != NULL){
            firstHalf = firstHalf -> next -> next;
            secondHalf = secondHalf -> next;
        }
        
        //뒷 부분을 거꾸로 돌려서 비교
        secondHalf = reverse(secondHalf);
        firstHalf = head;
        
        while(firstHalf != NULL && secondHalf != NULL){
            if(firstHalf -> val != secondHalf -> val){
                return false;
            }
            
            firstHalf = firstHalf -> next;
            secondHalf = secondHalf -> next;
        }               
        
        return true;        
    }
};