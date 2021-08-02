/***********************
 * Reverse Linked List *
 ***********************/

/*참고 : https://www.youtube.com/watch?v=MRe3UsRadKw
       : https://leetcode.com/problems/reverse-linked-list/solution/
       
*/
class Solution {
public:    
    //재귀 : 영상 참고
    ListNode* reverseList(ListNode* head) {
        //현재 또는 다음이 NULL이면 리턴, 마지막 값을 포인터로 만든다.
        if(head == NULL || head -> next == NULL){
            return head;
        }
        
        ListNode* ans = reverseList(head -> next);
        //다음 다음을 현재 node로 만들면 사이클이 생긴다. ex) 5 -> 4
        head -> next -> next = head;
        //다음 노드로 가는 연결을 끊으면 사이클이 없어진다.
        head -> next = NULL;
        
        return ans;
    }
    
    // 솔루션 참고
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(curr != NULL){
            //끝에 남아있는 하나씩을 포인터로 선정
            ListNode* temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        
        return prev;
    }
    
    
    ListNode* reverseList(ListNode* head) {
        //거꾸로 만들 게 없으면 리턴
        if(head == NULL){
            return head;
        }
        
        int len = 0;
        ListNode* temp = head;
        
        //linked list의 길이 체크
        while(temp){
            len++;
            temp = temp -> next;
        }
            
        temp = head;
        ListNode* ansR = new ListNode(0);
        ListNode* ans = ansR;
        
        //각 길이만큼 for문을 돈다.
        for(int i=0; i<len; i++){
            ListNode* temp2 = temp;
            
            //다음이 null이면, 첫 노드면 따로 설정
            if(temp2 -> next == NULL){
                ans -> next = temp2;
                break;
            }
            
            //temp2가 끝날 때까지 반복
            while(temp2){
                //다음 다음이 null이면 다음이 마지막 노드
                if((temp2 -> next) -> next == NULL){
                    
                    //다음 노드를 마지막 노드로 설정
                    ans -> next = temp2 -> next;
                    
                    //포인터를 다음 노드로 바꿈
                    ans = ans -> next;
                    
                    //마지막 노드 없앰
                    temp2 -> next = NULL;
                    
                    //while문 나가기
                    break;
                }
                else{
                    //마지막 까지 이동
                    temp2 = temp2 -> next;
                }
            }

        }
        //ansR은 정담 list 전에 0이 있는 상태이므로 next를 리턴
        return ansR -> next;
    }
    
};