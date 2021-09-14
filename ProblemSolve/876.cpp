/*****************************
 * Middle of the Linked List *
 *****************************/

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
    ListNode* middleNode(ListNode* head) {
        //한 ListNode는 한 칸씩, 한 ListNode는 두 칸씩 움직인다
        ListNode* tortoise = head;
        ListNode* hare = head;
        
        //두 칸씩 움직이는 ListNode가 더 이상 움직일 수 없는 경우 한 칸씩 움직이고 있던 ListNode는 중간 값에 도착한다
        //head의 길이가 n(n은 짝수)일 경우 n/2 + 1 번째부터 리턴해야 하므로 예외 상황을 처리해준다.
        //두칸을 움직일 수 없는 경우에는 한 칸씩 움직이는 ListNode가 n/2번째 값에 도착하므로 한 번 더 while문을 돌아줘야 한다
        while(hare -> next != NULL && hare != NULL){
            tortoise = tortoise -> next;
            hare = hare -> next;
            //더 움직일 수 없는 경우에는 움직이지 않는다
            //n/2 + 1번째 칸으로 도착할 수 있게, 오류가 나지 않게 확인해준다
            if(hare -> next == NULL){
                continue;
            }
            //한 칸 더 움직일 수 있는 경우에 더 움직여준다
            hare = hare -> next;
        }
                
        return tortoise;
    }
};