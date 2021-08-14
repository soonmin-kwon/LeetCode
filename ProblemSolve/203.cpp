/*******************************
 * Remove Linked List Elements *
 *******************************/

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {        
        if(head == NULL){
            return NULL;
        }
        
        //현재 값이 제거해야 되는 값이면 미리 제거한다
        while(head!=NULL && head->val==val){
           head=head->next;
        }
        
        //현재 값이 아니라 다음 값부터 확인하면 된다
        ListNode* temp = head;
        
        //다음과 현재가 널이 아니면
        while(temp != NULL && temp -> next != NULL){
            //다음 값이 제거해야 하는 값이면 다음을 다음 다음으로 넘겨서 제거한다
            if(temp -> next -> val == val){
                temp -> next = temp -> next -> next;
                continue;
            }
            temp = temp -> next;
        }
        
        return head;
    }
};