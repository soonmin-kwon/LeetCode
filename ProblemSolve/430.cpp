/*******************************************
 * Flatten a Multilevel Dobuly Linked List *
 *******************************************/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:    
    Node* flatten(Node* head) {
        if(head == NULL) {
           return NULL;
        }
        
        Node* headTemp = head;
        
        //모든 node탐색
        while(headTemp != NULL){
            //child를 next로 만들고 현재 next를 child와 연결된 리스트 다음에 연결해야한다
            if(headTemp -> child != NULL){                
                Node* temp = headTemp -> next;              //next 저장                
                headTemp -> next = headTemp -> child;       //현재 node의 next를 child로 만들고
                headTemp -> next -> prev = headTemp;        //next의 prev를 현재 node로 만들어 연결한다.
                headTemp -> child = NULL;                   //child를 끊어준다
                
                Node* temp2 = headTemp -> next; 
                
                //child와 연결된 리스트를 탐색한다
                while(temp2 -> next != NULL){
                    temp2 = temp2 -> next;
                }
                //제일 끝에 현재 node의 next를 연결해준다
                temp2 -> next = temp;
                
                //모든 node의 끝이 아니면 prev를 설정해준다
                if(temp != NULL){
                    temp -> prev = temp2;
                }                
            }
            
            headTemp = headTemp -> next;
        }
        
        return head;
    }
};