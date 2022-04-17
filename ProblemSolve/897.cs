/********************************
 * Increasing Order Search Tree *
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
    public List<int> SortBSTIncreasingOrder(TreeNode root, List<int> bstNodes){
        if(root == null){
            return null;
        }
        
        SortBSTIncreasingOrder(root.left, bstNodes);
        bstNodes.Add(root.val);
        SortBSTIncreasingOrder(root.right, bstNodes);
        
        return bstNodes;
    }
    
    public TreeNode IncreasingBST(TreeNode root) {
        List<int> nodes = SortBSTIncreasingOrder(root, new List<int>());
        TreeNode ans = new TreeNode(0);
        TreeNode ansTraverse = ans;
        foreach(int node in nodes){
            ansTraverse.right = new TreeNode(node);
            ansTraverse = ansTraverse.right;
        }
        
        return ans.right;
    }
}