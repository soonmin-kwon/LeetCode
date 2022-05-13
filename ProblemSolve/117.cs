/**************************************************
 * Populating Next Right Pointers in Each Node II *
 **************************************************/

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
    public Node HelpConnect(Node root, Node parent){
        if(root == null){
            return null;
        }
        
        if(parent == null){
            root.next = null;
        }
        else if(parent.right != null && parent.right != root){
            root.next = parent.right;
        }
        else{
            Node tempNode = parent.next;
            root.next = null;
            
            while(tempNode != null){
                if(tempNode.left != null){
                    root.next = tempNode.left;
                    break;
                }
                else if(tempNode.right != null){
                    root.next = tempNode.right;
                    break;
                }
                else{
                    tempNode = tempNode.next;
                }
            }
        }        
        
        HelpConnect(root.right, root);
        HelpConnect(root.left, root);
        
        return root;
    }
    
    public Node Connect(Node root, Node parent = null) {
        HelpConnect(root, new Node());
        return root;
    }
}