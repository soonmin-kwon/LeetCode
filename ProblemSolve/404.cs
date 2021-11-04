/**********************
 * Sum of Left Leaves *
 **********************/

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
    public int SumOfLeftLeaves(TreeNode root, bool isLeft = false) {
        if(root == null){
            return 0;
        }
        
        int ans = 0;
        
        //left leaf면 정답에 더해준다
        do{
            if(root.left != null){
                break;
            }
            
            if(root.right != null){
                break;
            }
            
            if(!isLeft){
                break;
            }
            
            ans += root.val;
            return ans;
        }while(false);
        
        ans = SumOfLeftLeaves(root.left, true) + SumOfLeftLeaves(root.right, false);
        
        return ans;
    }
}