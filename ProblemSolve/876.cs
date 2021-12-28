/*****************************
 * Middle of the Linked List *
 *****************************/

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
    public ListNode MiddleNode(ListNode head) {
        ListNode hare = head;
        ListNode tortoise = head;
        
        //Tortoise & Hare Algorithm. 중간값 또는 사이클 여부를 찾을 수 있음
        while(hare != null && hare.next != null){
            hare = hare.next.next;
            tortoise = tortoise.next;
        }
        
        return tortoise;
    }
}