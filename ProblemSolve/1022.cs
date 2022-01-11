/**************************************
 * Sum of Root To Leaf Binary Numbers *
 **************************************/

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
    public int SumRootToLeaf(TreeNode root, int curSum = 0) {
        if(root == null){
            return 0;
        }
        
        if(root.left == null && root.right == null){
            return 2 * curSum + root.val;
        }
        
        return SumRootToLeaf(root.left, 2 * curSum + root.val) + SumRootToLeaf(root.right, 2 * curSum + root.val);
    }
}