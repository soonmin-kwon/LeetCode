/**************************************************************
 * Construct Binary Tree from Inorder and Postorder Traversal *
 **************************************************************/

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
    public TreeNode MakeTree(ref int[] inorder, ref int[] postorder, int leftIn, int rightIn, int leftPo, int rightPo){
        if(leftIn > rightIn || leftPo > rightPo){
            return null;
        }
        
        TreeNode node = new TreeNode(postorder[rightPo]);
        int border = leftIn;
        //left와 right의 경계를 구한다.
        //inorder는 left, root, right이므로, postorder에서 root값을 찾고 
        //inorder에서 root값을 찾으면 그 값을 기준으로 left, right를 나눌 수 있다
        while(node.val != inorder[border]){
            border++;
        }
        
        //postorder는 left, right, root이고 위에서 left와 right의 경계를 찾았다.
        //그 길이만큼 자르면 left, right 범위에서 각각 root를 찾을 수 있다.
        node.left = MakeTree(ref inorder, ref postorder, leftIn, border-1, leftPo, leftPo+border-leftIn-1);
        node.right = MakeTree(ref inorder, ref postorder, border+1, rightIn, leftPo+border-leftIn, rightPo-1);
        
        return node;
    }
    public TreeNode BuildTree(int[] inorder, int[] postorder) {
        
        return MakeTree(ref inorder, ref postorder, 0, inorder.Length-1, 0, postorder.Length-1);
    }
}