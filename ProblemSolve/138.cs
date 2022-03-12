/*********************************
 * Copy List with Random Pointer *
 *********************************/

/*
// Definition for a Node.
public class Node {
    public int val;
    public Node next;
    public Node random;
    
    public Node(int _val) {
        val = _val;
        next = null;
        random = null;
    }
}
*/

public class Solution {
    public Node CopyRandomList(Node head) {
        if(head == null)
            return null;
        
        Node p1 = head;
        Node p2 = null;
        
        while(p1 != null){
            p2 = new Node(p1.val);
            p2.next = p1.next;
            p1.next = p2;
            p1 = p1.next.next;
        }
        
        p1 = head;
        
        while(p1 != null){
            if(p1.random != null)
                p1.next.random = p1.random.next;
            
            p1 = p1.next.next;
        }
        
        p1 = head;
        Node ans = head.next;
        
        while(p1 != null){
            p2 = p1.next;
            p1.next = p2.next;
            
            if(p2.next != null)
                p2.next = p2.next.next;
            
            p1 = p1.next;
        }
        
        return ans;
    }
}