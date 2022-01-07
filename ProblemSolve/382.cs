/***************************
 * Linked List Random Node *
 ***************************/

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

//참고 : https://trancekim.tistory.com/3

public class Solution {
    ListNode head;
    Random rand = new Random();
    
    public Solution(ListNode head) {
        this.head = head;
    }
    
    public int GetRandom() {
        double idx = 2.0;
        double selectedProb = 0.5;
        int returnValue = head.val;
        ListNode pointer = head.next;
        
        while(pointer != null){
            if(rand.NextDouble() < selectedProb){
                returnValue = pointer.val;
            }
            
            pointer = pointer.next;
            selectedProb *= (idx++ / idx);
        }
        
        return returnValue;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.GetRandom();
 */