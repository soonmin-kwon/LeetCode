/***************
 * Rotate List *
 ***************/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */

public class Solution {
    public ListNode RotateRight(ListNode head, int k) {
        int length = 1;
        
        ListNode firstHead = head;
        
        if(head == null){
            return null;
        }
                
        while(head.next != null){
            head = head.next;
            
            length++;
            
            if(head.next == null){
                head.next = firstHead;
                break;
            }            
        }
        
        if(length == 1){            
            return head;
        }
        
        length = length - k % length;
        
        for(int i=0; i<length-1; ++i){
            firstHead = firstHead.next;
        }
        
        ListNode ans = firstHead.next;
        firstHead.next = null;
        
        return ans;
    }
}