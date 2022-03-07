/**************************
 * Merge Two Sorted Lists *
 **************************/

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
    public ListNode MergeTwoLists(ListNode list1, ListNode list2) {
        ListNode list1Pointer = list1;
        ListNode list2Pointer = list2;
        
        ListNode ans = new ListNode();        
        ListNode ansPointer = ans;
        
        while(list1Pointer != null && list2Pointer != null){
            if(list1Pointer.val > list2Pointer.val){
                ansPointer.next = list2Pointer;
                list2Pointer = list2Pointer.next;
            }
            else{
                ansPointer.next = list1Pointer;
                list1Pointer = list1Pointer.next;
            }
            
            ansPointer = ansPointer.next;
        }
        
        if(list1Pointer != null){
            ansPointer.next = list1Pointer;
        }
        else{
            ansPointer.next=  list2Pointer;            
        }
        
        return ans.next;
    }
}