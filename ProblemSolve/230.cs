/*********************************
 * Kth Smallest Element in a BST *
 *********************************/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

public class Solution {
    public void findKthSmallestNode(TreeNode root, ref int nodeVal, ref int curr, ref int k){
        if(root == null)
            return;
        
        findKthSmallestNode(root.left, ref nodeVal, ref curr, ref k);
        curr++;
        if(curr == k){
            nodeVal = root.val;
            return;
        }
        findKthSmallestNode(root.right, ref nodeVal, ref curr, ref k);
        
        return;
    }
    
    public int KthSmallest(TreeNode root, int k) {
        int ans = 0;
        int curr = 0;
        
        findKthSmallestNode(root, ref ans, ref curr, ref k);
        
        return ans;
    }
}