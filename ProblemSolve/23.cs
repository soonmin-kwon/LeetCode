/************************
 * Merge K Sorted Lists *
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
    public ListNode MergeKLists(ListNode[] lists) {
        ListNode ans = new ListNode();
        ListNode pointer = ans;        
                
        PriorityQueue<ListNode, int> pq = new PriorityQueue<ListNode, int>();
        
        for(int i=0; i<lists.Length; ++i){                        
            if(lists[i] != null)
                pq.Enqueue(lists[i], lists[i].val);
        }
        
        while(pq.TryDequeue(out ListNode list, out int val)){
            pointer.next = new ListNode(val);
            pointer = pointer.next;
            list = list.next;
            
            if(list != null){
                pq.Enqueue(list, list.val);
            }
        }
        
        return ans.next;
    }
}