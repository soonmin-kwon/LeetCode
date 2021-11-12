/*******************************
 * Remove Linked List Elements *
 *******************************/

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
    public ListNode RemoveElements(ListNode head, int val) {
        if(head == null){
            return head;
        }
        
        //시작 값이 제거해야 하는 값이면 미리 제거
        while(head != null && head.val == val){
            head = head.next;
        }
        
        ListNode headTemp = head;
        
        while(headTemp != null && headTemp.next != null){
            //다음 노드를 지워야 하면 현재 노드의 다음 노드를 다다음 노드로 연결해버리면
            //다음 노드를 지워야 하는 것과 같은 효과를 낸다.
            if(headTemp.next.val == val){
                headTemp.next = headTemp.next.next;
                continue;
            }
            
            headTemp = headTemp.next;
        }
        
        return head;
    }
}