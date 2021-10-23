/******************
 * Partition List *
 ******************/

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
    ListNode* partition(ListNode* head, int x) {
        //x값보다 작은 값들을 이어놓을 list의 head
        ListNode* lessList = new ListNode();
        //lessTemp를 이용해 작은 값들을 이어놓는다
        ListNode* lessTemp = lessList;
        
        //x값보다 큰 값들을 이어놓을 list의 head
        ListNode* greaterList = new ListNode();
        //greaterTemp를 이용해 큰 값들을 이어놓는다
        ListNode* greaterTemp = greaterList;
        
        //주어진 list를 전부 돈다
        while(head != NULL){
            //x값보다 작으면
            if(head -> val < x){
                //lessTemp를 이용해 lessList에 붙인다
                lessTemp -> next = head;
                lessTemp = lessTemp -> next;
            }
            //x값보다 크면
            else{
                //greaterTemp를 이용해 greateList에 붙인다
                greaterTemp -> next = head;
                greaterTemp = greaterTemp -> next;
            }
            
            //list 순회
            head = head -> next;
        }
        
        //lessList 에 greaterList를 이어붙이는 것이기 때문에 greaterList의 마지막은 Null로 끝난다
        greaterTemp -> next = NULL;
        
        //ex) x == 4, head => 1(head) -> 2 -> 3 -> 5 -> 4 -> 1 -> NULL
        //lessList => 0(lessList) -> 1 -> 2 -> 3 -> 1(listTemp) -> NULL
        //greaterList => 0 (lessList) -> 5 -> 4(greaterTemp) -> NULL
        //listTemp -> next에 greaterList -> next를 이어붙이고 listList -> next를 return하면 원하는 결과가 나온다
        //0(lessList) -> 1 -> 2 -> 3 -> 1 -> 5 -> 4 -> NULL
        lessTemp -> next = greaterList -> next;
        
        //1 -> 2 -> 3 -> 1 -> 5 -> 4
        return lessList -> next;
    }
};