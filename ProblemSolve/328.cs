/************************
 * Odd Even Linked List *
 ************************/

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
    public ListNode OddEvenList(ListNode head) {
        if(head == null){
            return null;
        }
        //홀수, 짝수번째 노드들을 담는 리스트들
        ListNode oddList = head;
        ListNode evenList = head.next;
        
        //짝수번째 노드들을 담은 리스트의 시작점을 기억
        ListNode evenListHead = evenList;
        
        //odd은 1번째, even은 2번째 노드를 가리킨다고 하면
        //odd의 다음은 3번째가 되어야 하므로 even의 next
        //even의 다음은 4번째가 되어야 하므로 odd를 3번째로 옮기고 그 다음 걸 참조하면 됨.
        while(evenList != null && evenList.next != null){            
            oddList.next = evenList.next;
            oddList = oddList.next;
            evenList.next = oddList.next;
            evenList = evenList.next;
        }
        
        //이어 붙이기
        oddList.next = evenListHead;
        
        return head;
    }
}