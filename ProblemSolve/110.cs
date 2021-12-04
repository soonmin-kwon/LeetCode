/************************
 * Balanced Binary Tree *
 ************************/

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
    public int HeightOfSubtree(TreeNode root, ref bool ans) {
        if(root == null || ans == false){
            return 0;
        }
        
        int leftSubHeight = HeightOfSubtree(root.left, ref ans);
        int rightSubHeight = HeightOfSubtree(root.right, ref ans);
        
        if((leftSubHeight - rightSubHeight < -1) || (leftSubHeight - rightSubHeight > 1)){
            ans = false;
        }
        
        return 1 + Math.Max(leftSubHeight, rightSubHeight);
    }
    
    public bool IsBalanced(TreeNode root) {
        bool ans = true;
        HeightOfSubtree(root, ref ans);
        return ans;
    }
}