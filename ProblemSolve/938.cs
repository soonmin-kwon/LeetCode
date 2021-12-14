/********************
 * Range Sum of BST *
 ********************/

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
    int sum = 0;
    
    public int RangeSumBST(TreeNode root, int low, int high) {
        if(root == null){
            return sum;
        }
        
        //BST이기 때문에 현재 값이 범위 밖에 있으면 일부 범위를 탐색하지 않아도 됨.
        if(root.val < low){
            sum = RangeSumBST(root.right, low, high);
        }
        else if(root.val > high){
            sum = RangeSumBST(root.left, low, high);
        }
        else{
            sum += root.val;
            sum = RangeSumBST(root.left, low, high);
            sum = RangeSumBST(root.right, low, high);
        }
        
        return sum;
    }
}