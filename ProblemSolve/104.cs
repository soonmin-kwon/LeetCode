/********************************
 * Maximum Depth of Binary Tree *
 ********************************/

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
    int depth = 0;
    void Traverse(TreeNode root, int currDepth){
        if(root == null){
            return;
        }
        
        Traverse(root.left, currDepth + 1);
        Traverse(root.right, currDepth + 1);
        
        depth = Math.Max(depth, currDepth);                
    }
    
    public int MaxDepth(TreeNode root) {
        Traverse(root, 1);
        return depth;
    }
}