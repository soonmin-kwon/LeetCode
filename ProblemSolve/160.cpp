/************************************
 * Intersection of Two Linked Lists *
 ************************************/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        
        int lenA = 0;
        int lenB = 0;
        
        //headA의 길이 측정
        while(tempA != NULL){
            lenA++;
            tempA = tempA -> next;
        }
        
        //headB의 길이 측정
        while(tempB != NULL){
            lenB++;
            tempB = tempB -> next;
        }
        
        //길이 차이를 구해서 차이만큼 미리 움직인 다음 같이 움직이면 만나는 지점이 정답
        int gap = lenB - lenA;
        
        //길이 차이만큼 미리 움직인다
        if(gap < 0){
            while(gap != 0){
                headA = headA -> next;
                gap++;
            }
        }
        else if(gap > 0){
            while(gap != 0){
                headB = headB -> next;
                gap--;
            }
        }
        
        ListNode* ans;
        
        //한칸씩 움직이면서 같은 값이 나오면 리턴
        while(headA != NULL){
            if(headA == headB){
                return headA;                
            }
            
            headA = headA -> next;
            headB = headB -> next;
        }
        
        return ans;
    }
};