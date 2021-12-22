/****************
 * Reorder List *
 ****************/

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
    public void ReorderList(ListNode head) {
        if(head == null || head.next == null){
            return;
        }
        
        ListNode firstHalf = head;
        ListNode reversedSecondHalf = head.next;
        
        //ListNode의 중앙 값 찾는 방법
        while(reversedSecondHalf != null && reversedSecondHalf.next != null){
            firstHalf = firstHalf.next;
            reversedSecondHalf = reversedSecondHalf.next.next;
        }
        
        //ListNode를 뒤집는 방법
        ListNode tempForReverse = firstHalf.next;
        firstHalf.next = null;
        
        reversedSecondHalf = tempForReverse.next;
        tempForReverse.next = null;
        
        while(reversedSecondHalf != null){
            firstHalf = reversedSecondHalf.next;
            reversedSecondHalf.next = tempForReverse;
            tempForReverse = reversedSecondHalf;
            reversedSecondHalf = firstHalf;
        }
        
        //두 ListNode를 지그재그로 합치는 방법
        firstHalf = head;
        reversedSecondHalf = tempForReverse;
        
        while(firstHalf != null){
            ListNode temp = firstHalf.next;
            firstHalf.next = reversedSecondHalf;
            firstHalf = firstHalf.next;
            reversedSecondHalf = temp;
        }
    }
}