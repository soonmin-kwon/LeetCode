/************************************************
 * Maximum Difference Between Node and Ancestor *
 ************************************************/

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
    public int GetMaxAncestorDiff(TreeNode root, int max, int min){
        if(root == null){
            return (max - min);
        }
        
        max = Math.Max(root.val, max);
        min = Math.Min(root.val, min);
        
        int leftMax = GetMaxAncestorDiff(root.left, max, min);
        int rightMax = GetMaxAncestorDiff(root.right, max, min);
        
        return Math.Max(leftMax, rightMax);
    }
    
    public int MaxAncestorDiff(TreeNode root) {
        if(root == null){
            return 0;
        }
        
        return GetMaxAncestorDiff(root, root.val, root.val);
    }
}