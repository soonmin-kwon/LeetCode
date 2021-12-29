/***********************************************
 * Populating Next Right Pointers in Each Node *
 ***********************************************/

/*
// Definition for a Node.
public class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
}
*/

public class Solution {
    public Node Connect(Node root) {
        //leaf면 리턴
        if(root == null || root.left == null || root.right == null){
            return root;
        }
        
        //리프 아니면 무조건 left, right가 있음, perfect binary tree이기 때문에
        //왼쪽 자식, 오른쪽 자식 연결
        root.left.next = root.right;
        
        //끝 노드가 아니면 오른쪽 자식의 next는 현재 노드의 next의 왼쪽 자식
        if(root.next != null){
            root.right.next = root.next.left;
        }
        else{
            //끝 노드면 null로 연결
            root.right.next = null;
        }
        
        //DFS
        Connect(root.left);
        Connect(root.right);
        
        return root;
    }
}