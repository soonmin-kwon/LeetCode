/************************************
 * Insert into a Binary Search Tree *
 ************************************/

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
    
    public TreeNode InsertIntoBST(TreeNode root, int val) {
        if(root == null){
            return new TreeNode(val);
        }
        
        //BST 특성 살리기
        //현재 root보다 작으면 왼쪽에 가야 함.
        if(root.val > val){
            //왼쪽이 비어 있으면 넣어주고 비어있지 않으면 더 탐색해야 함.
            if(root.left == null){
                root.left = new TreeNode(val);
            }
            else{
                InsertIntoBST(root.left, val);
            }
        }
        //현재 root보다 크면 오른쪽으로 가야 함.
        else{
            //오른쪽이 비어 있으면 넣어주고 비어있지 않으면 더 탐색함.
            if(root.right == null){
                root.right = new TreeNode(val);
            }
            else{
                InsertIntoBST(root.right, val);
            }
        }
        
        return root;
    }
}