/*********************
 * Linked List Cycle *
 *********************/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */

public class Solution {
    public bool HasCycle(ListNode head) {
        if(head == null){
            return false;
        }
        
        ListNode tortoise = head;
        ListNode hare = head;
        
        while(hare.next != null && hare.next.next != null){
            tortoise = tortoise.next;
            hare = hare.next.next;
            
            if(tortoise == hare){
                return true;
            }
        }
        
        return false;
    }
}