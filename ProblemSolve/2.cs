/*******************
 * Add Two Numbers *
 *******************/

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
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        int sum = 0;
        
        ListNode ans = new ListNode();
        ListNode ansPointer = ans;
        
        while(sum != 0 || l2 != null || l1 != null){
            if(l1 != null){
                sum += l1.val;
                l1 = l1.next;
            }
            
            if(l2 != null){
                sum += l2.val;
                l2 = l2.next;
            }
            
            
            ansPointer.next = new ListNode(sum % 10);
            ansPointer = ansPointer.next;
            sum /= 10;            
        }
        
        return ans.next;
    }
}