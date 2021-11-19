/************************
 * Linked List Cycle II *
 ************************/

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
    public ListNode DetectCycle(ListNode head) {
        if(head == null){
            return null;
        }
        
        if(head.next == null){
            return null;
        }
        
        //Tortoise & Hare Algorithm        
       //사이클을 찾는 전형적인 알고리즘
        ListNode tortoise = head.next;
        ListNode hare = head.next.next;
        
        while(hare != null && hare.next != null){
            tortoise = tortoise.next;
            hare = hare.next.next;
            
            //cycle이 생기면
            if(tortoise == hare){
                tortoise = head;
                
                //cycle이 생긴 자리를 찾는 방법
                while(tortoise != hare){
                    tortoise = tortoise.next;
                    hare = hare.next;
                }
                
                return tortoise;
            }
        }
        
        return null;
    }
}