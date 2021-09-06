/*********************************
 * N-ary Tree Preorder Traversal *
 *********************************/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    //recursive
    void traversal(vector<int>& ans, Node* root){
        if(root == NULL){
            return;
        }
        //전형적인 preorder 진행
        ans.push_back(root -> val);
        
        for(auto x : root -> children){
            traversal(ans, x);
        }
        
        return;
    }
    
    vector<int> preorder(Node* root) {
        vector<int> ans;
        traversal(ans, root);
        
        return ans;
    }
    
    //iterative
    vector<int> preorder(Node* root) {
        vector<int> ans;
        
        if(root == NULL){
            return ans;
        }
        //스택에 right -> left 순으로 저장하게 되면 preorder의 순서대로 진행할 수 있다
        stack<Node*> s;
        s.push(root);
        Node* temp;
        
        while(!s.empty()){
            temp = s.top();
            s.pop();
            ans.push_back(temp -> val);
            
            //현재 root에 연결되어있는 모든 child를 거꾸로 스택에 넣는다
            //현재 root에 연결된 첫 child가 스택의 top에 올라오게 되면서 preorder의 순서인 root, left, right 순을 맞출 수 있다
            for(int i=(temp -> children).size() - 1; i>=0; i--){
                s.push((temp -> children)[i]);
            }
        }
                
        return ans;
    }
};