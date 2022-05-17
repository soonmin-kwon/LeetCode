/**********************************************************************
 * Find a Corresponding Node of a Binary Tree in a Clone of That Tree *
 **********************************************************************/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */

public class Solution {
    TreeNode ans = null;
    TreeNode target = null;
    
    public void Inorder(TreeNode original, TreeNode cloned){
        if(original == null){
            return;
        }
        
        Inorder(original.left, cloned.left);
        
        if(original == target){
            ans = cloned;
        }
        
        Inorder(original.right, cloned.right);
    }
    
    public TreeNode GetTargetCopy(TreeNode original, TreeNode cloned, TreeNode target) {
        this.target = target;
        
        Inorder(original, cloned);
        
        return ans;
    }
}