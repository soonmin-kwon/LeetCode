/************************************
 * Remove Nth Node From End of List *
 ************************************/

class Solution {
public:
    int count = 0;
    //재귀
    ListNode* removeNthFromEnd(ListNode* head, int n) {        
        //현재 노드가 NULL이 아니면
        if (head != NULL) {
            //다음 노드로 넘어가서 체크
            head -> next = removeNthFromEnd(head -> next, n);
            //노드가 NULL이면 끝나기 때문에 가장 뒤에서부터 카운트가 세짐
            count++;
            
            //카운트가 없애려고 하는 노드의 번호와 일치하면 그 노드를 생략
            if (count==n) {
                head = head -> next;
            }
        }
        
        return head;        
    }
    
    //단순 진행
    ListNode* removeNthFromEnd(ListNode* head, int n) {        
        ListNode* temp = head;
        
        //전체 linked list의 길이를 먼저 측정
        int len = 0;
        while(temp != NULL){
            temp = temp -> next;
            len++;
        }
        
        //없애려는 노드의 한칸 전으로 간다.
        int idx = len - n - 1;
        
        //첫번째 노드를 없애려고 한다면 바로 리턴
        if(idx < 0){
            head = head -> next;
            return head;
        }
        
        //다시 복사
        temp = head;
        
        //없애려는 노드의 한칸 전으로 이동
        while(idx){
            temp = temp -> next;
            idx--;
        }
        
        //다음 다음 노드가 NULL이면 없애려는 노드가 마지막 노드가 되므로
        if((temp -> next) -> next == NULL){
            //다음을 NULL로 바꿈
            temp -> next = NULL;
        }
        //다음 다음이 NULL이 아니면
        else{
            //다음을 스킵
            temp -> next = (temp -> next) -> next;
        }
        
        return head;
    }
};