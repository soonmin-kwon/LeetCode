/**************************************************
 * Populating Next Right Pointers in Each Node II *
 **************************************************/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root, Node* parent = new Node()) {
        //root가 NULL인 경우 NULL return
        if(root == NULL){
            return NULL;
        }
        
        //시작 root인 경우 무조건 next는 NULL
        if(parent == NULL){
            root -> next = NULL;
        }
        //현재 root의 부모 노드의 다른 child에 연결할 수 있는 경우 연결한다
        else if(parent -> right != NULL && parent -> right != root){
            root -> next = parent -> right;
        }
        //현재 root의 부모 노드의 다른 child에 연결할 수 없는 경우
        else{
            //부모 노드의 next 노드를 기준으로 연결할 수 있는 노드가 있는지 확인한다
            Node* temp = parent -> next;
            //NULL을 디폴트로 잡는다, 연결할 수 없는 경우 다른 설정을 하지 않아도 된다
            root -> next = NULL;
            
            //부모 노드의 next 노드가 NULL이 아닌 경우
            while(temp != NULL){
                //left child가 있으면 그 child에 연결해야만 한다
                if(temp -> left != NULL){
                    root -> next = temp -> left;
                    break;
                }
                //left child가 없고 right child만 있으면 그 child에 연결해야만 한다
                else if(temp -> right != NULL){
                    root -> next = temp -> right;
                    break;
                }
                
                //연결할 수 있는 노드가 있는지 확인하기 위해 next로 이동하면서 확인한다
                //ex)
                /*
                                1
                        2              3
                    4       5       6
                7
                
                현재 root = 7, 시작 temp = 5, 5에 연결할 child가 없기 때문에 6으로 이동
                6에도 연결할 child가 없고 temp = NULL로 이동
                while문 끝
                */
                else{
                    temp = temp -> next;
                }
            }
        }
        
        //재귀적으로 접근
        connect(root -> right, root);
        connect(root -> left, root);
        
        return root;
    }
};