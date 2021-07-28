/**************************************
 * Remove Duplicates from Sorted List *
 **************************************/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {        
        ListNode* ans = head;
        
        //예외처리
        if(head == nullptr){
            return head;
        }
        
        //다음이 nullptr이면 끝
        while(head -> next != nullptr){
            //지금 값과 다음 값이 같으면 다다음 값을 다음 값으로 설정해 다음 값을 삭제
            if(head -> val == head -> next -> val){
                head -> next = head -> next -> next;
            }
            //다르면 그대로 유지
            else{
                head = head -> next;
            }
        }
        
        return ans;
    }
};