/***********************************
 * Swapping Nodes in a Linked List *
 ***********************************/

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
    public void Swap(ref int a, ref int b){
        int temp = a;
        a = b;
        b = temp;
    }
    
    public ListNode SwapNodes(ListNode head, int k) {
        ListNode pointer1 = head, pointer2 = head, kthNode = null;
        
        while(k-- > 1){
            pointer1 = pointer1.next;
        }
        
        kthNode = pointer1;
        pointer1 = pointer1.next;
        
        while(pointer1 != null){
            pointer1 = pointer1.next;
            pointer2 = pointer2.next;
        }
        
        Swap(ref kthNode.val, ref pointer2.val);
        
        return head;
    }
}