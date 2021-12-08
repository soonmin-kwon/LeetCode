/********************
 * Binary Tree Tilt *
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
    //Postorder로 돌면서 확인
    public int CalNodeSumAndTiltSum(TreeNode root, ref int tiltSum){
        if(root == null){
            return 0;
        }
        
        int leftSubtreeSum = CalNodeSumAndTiltSum(root.left, ref tiltSum);
        int rightSubtreeSum = CalNodeSumAndTiltSum(root.right, ref tiltSum);
        
        tiltSum += Math.Abs(leftSubtreeSum - rightSubtreeSum);
        
        return root.val + leftSubtreeSum + rightSubtreeSum;
    }
    
    public int FindTilt(TreeNode root) {
        int tiltSum = 0;
        
        CalNodeSumAndTiltSum(root, ref tiltSum);
        return tiltSum;
    }
}