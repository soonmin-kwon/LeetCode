/*************
 * Sort List *
 *************/

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
    public ListNode SortList(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }
        
        ListNode secondHalf = GetSecondHalf(head);
        ListNode left = SortList(head);
        ListNode right = SortList(secondHalf);
        
        return Merge(left, right);
    }
    
    public ListNode Merge(ListNode left, ListNode right){
        ListNode pointer = new ListNode();
        ListNode mergedList = pointer;
        
        while(left != null && right != null){
            if(left.val > right.val){
                pointer.next = right;
                right = right.next;
            }
            else{
                pointer.next = left;
                left = left.next;
            }
            
            pointer = pointer.next;
        }
        
        if(left != null){
            pointer.next = left;
        }
        else{
            pointer.next = right;
        }
        
        return mergedList.next;
    }
    
    public ListNode GetSecondHalf(ListNode head){
        ListNode tortoise = head;
        ListNode hare = head.next.next;
        
        while(hare != null && hare.next != null){
            tortoise = tortoise.next;
            hare = hare.next.next;
        }
        
        ListNode secondHalf = tortoise.next;
        tortoise.next = null;
        
        return secondHalf;
    }
}