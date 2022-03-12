/*********************************
 * Copy List with Random Pointer *
 *********************************/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
                
        Node* p1 = head;
        Node* p2 = NULL;
        
        while(p1 != NULL){
            p2 = new Node(p1 -> val);
            p2 -> next = p1 -> next;
            p1 -> next = p2;
            p1 = p1 -> next -> next;
        }
        
        p1 = head;
        
        while(p1 != NULL){
            if(p1 -> random != NULL)
                p1 -> next -> random = p1 -> random -> next;
            
            p1 = p1 -> next -> next;
        }
        
        p1 = head;
        Node* ans = head -> next;
        
        while(p1 != NULL){
            p2 = p1 -> next;
            p1 -> next = p2 -> next;
            
            if (p2 -> next != NULL)
                p2 -> next = p2 -> next -> next;
            
            p1 = p1 -> next;
        }
        
        return ans;
    }
};