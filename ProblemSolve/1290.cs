/*****************************************************
 * Convert Binary Number in a Linked List to Integer *
 *****************************************************/

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
    public int GetDecimalValue(ListNode head) {
        int ans = 0;
        
        //제일 위에 비트부터 계산. 다음 비트가 나오면 x2해서 shift
        //현재 값 추가
        while(head != null){
            ans *= 2;
            ans += head.val;
            head = head.next;
        }
        
        return ans;
    }
}