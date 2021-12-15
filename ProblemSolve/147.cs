/***********************
 * Insertion Sort List *
 ***********************/

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
    public ListNode InsertionSortList(ListNode head) {
        ListNode ans = new ListNode();
        
        //하나씩 확인
        //head에서 확인할 수를 하나 고르고, ans를 순회하면서 들어갈 자리를 찾는다
        while(head != null){
            ListNode headPointer = head;
            ListNode ansPointer = ans;
            head = head.next;
            
            while(ansPointer.next != null && ansPointer.next.val < headPointer.val){
                ansPointer = ansPointer.next;
            }
            
            headPointer.next = ansPointer.next;
            ansPointer.next = headPointer;
        }
        
        return ans.next;
    }
}