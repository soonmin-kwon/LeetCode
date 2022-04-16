/*******************************
 * Convert BST to Greater Tree *
 *******************************/

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
    private int greaterSum = 0;
    public TreeNode ConvertBST(TreeNode root) {
        if(root == null){
            return null;
        }
        
        ConvertBST(root.right);
        greaterSum += root.val;
        root.val = greaterSum;
        ConvertBST(root.left);
        
        return root;
    }
}