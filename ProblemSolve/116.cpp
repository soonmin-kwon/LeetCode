/***********************************************
 * Populating Next Right Pointers in Each Node *
 ***********************************************/

class Solution {
public:
    Node* connect(Node* root) {
        //leaf면 리턴, perfect binary tree
        if(root == NULL || root -> left == NULL || root -> right == NULL){
            return root;
        }
        
        root-> left -> next = root -> right;
        
        //오른쪽 끝 노드가 아니면
        if(root -> next != NULL){
            //right child의 next는 next node의 left child
            root -> right -> next= root -> next -> left;
        }
        //오른쪽 끝 노드면
        else{
            //다음 노드를 null로 설정
            root -> right -> next = NULL;
        }
        
        connect(root -> left);
        connect(root -> right);
        
        return root;
    }
};