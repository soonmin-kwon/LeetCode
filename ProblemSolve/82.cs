/*****************************************
 * Remove Duplicates from Sorted List II *
 *****************************************/

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
    public ListNode DeleteDuplicates(ListNode head) {
        ListNode ans = new ListNode(0, head);
        
        ListNode ansPointer = ans;
        
        while(head != null){
            if(head.next != null && head.val == head.next.val){
                while(head.next != null && head.val == head.next.val){
                    head = head.next;
                }
                
                ansPointer.next = head.next;
            }
            else{
                ansPointer = ansPointer.next;
            }
            
            head = head.next;            
        }
        
        return ans.next;
    }
}