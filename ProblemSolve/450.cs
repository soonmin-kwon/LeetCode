/************************
 * Delete Node in a BST *
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
    public TreeNode DeleteNode(TreeNode root, int key) {
        if(root == null){
            return null;
        }
        //BST이기 때문에 더 빠르게 key 값을 가진 node에 도달 가능
        if(root.val < key){
            root.right = DeleteNode(root.right, key);
        }
        else if(root.val > key){
            root.left = DeleteNode(root.left, key);
        }
        else{
            //leaf인 경우
            if(root.left == null && root.right == null){
                return null;
            }
            
            //자식이 하나인 경우
            if(root.left == null || root.right == null){
                return root.left == null ? root.right : root.left;
            }
            
            //자식이 두개인 경우 양쪽 subtree에서의 중간 값을 찾아서 root의 값으로 넣어줘야 한다.
            //left subtree에서 제일 큰 값을 찾거나, right subtree에서 가장 작은 값을 찾으면 된다.
            //right subtree에서 제일 작은 값을 찾는다.
            TreeNode temp = root.right;            
            while(temp.left != null){
                temp = temp.left;
            }
            
            root.val = temp.val;
            root.right = DeleteNode(root.right, root.val);
        }
        
        return root;
    }
}