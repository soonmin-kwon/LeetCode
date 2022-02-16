/***********************
 * Swap Nodes in Pairs *
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
    public ListNode SwapPairs(ListNode head) {
        //끝에 하나거나 딱 맞아 떨어지면 그냥 리턴
        if(head == null || head.next == null){
            return head;
        }
        // 1 -> 2 -> 3 -> 4일때
        // ans = 2 -> 3 -> 4, head.next = 3 -> 4를 가지고 이 함수를 돈 결과
        // 3 -> 4 일때,
        // ans = 4, ans.next = head. 4 -> 3 => 스왑
        // 다시 위로 돌아가서 head = 1 -> 4 -> 3
        // ans = 2 -> 3 -> 4. ans.next = head => 2 -> 1 -> 4 -> 3
        ListNode ans = new ListNode();
        ans = head.next;
        head.next = SwapPairs(head.next.next);
        
        ans.next = head;                
        
        return ans;
    }
}