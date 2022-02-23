/***************
 * Clone Graph *
 ***************/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> copied;
    
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        
        //중복 방지
        if(copied.find(node) != copied.end()){
            return copied[node];
        }
        
        copied[node] = new Node(node -> val);
        for(Node* neighbor : node -> neighbors){
            copied[node] -> neighbors.push_back(cloneGraph(neighbor));
        }
        
        return copied[node];
    }
};