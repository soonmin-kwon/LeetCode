/********************************
 * Delete Node in a Linked List *
 ********************************/

class Solution {
public:    
    void deleteNode(ListNode* node) {
        //다음 거 스킵
        *node = *(node->next);
        return;
    }
    
    void deleteNode(ListNode* node) {
        //다음 노드 저장하는 임시 list 생성
        ListNode* temp = node -> next;
        
        //현재 노드 없앰
        *node = *temp;
        
        //release
        temp = NULL;
        delete temp;
        
        return;
    }
};