/********************************
 * Maximum Width of Binary Tree *
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
    public int WidthOfBinaryTree(TreeNode root) {
        if(root == null){
            return 0;
        }
        
        Queue<KeyValuePair<TreeNode, ulong>> queue = new Queue<KeyValuePair<TreeNode, ulong>>();
        
        int ans = 0;
        
        queue.Enqueue(new KeyValuePair<TreeNode, ulong>(root, 0));
        
        while(queue.Count > 0){
            ulong leftIdx = queue.Peek().Value;
            ulong rightIdx = 0;
            int len = queue.Count;
            
            for(int i=0; i<len; ++i){
                KeyValuePair<TreeNode, ulong> nodeVal = queue.Dequeue();
                
                rightIdx = nodeVal.Value;
                
                if(nodeVal.Key.left != null){
                    queue.Enqueue(new KeyValuePair<TreeNode, ulong>(nodeVal.Key.left, 2*rightIdx + 1));
                }
                
                if(nodeVal.Key.right != null){
                    queue.Enqueue(new KeyValuePair<TreeNode, ulong>(nodeVal.Key.right, 2*rightIdx + 2));
                }
            }
            
            ans = Math.Max(ans, (int)(rightIdx - leftIdx + 1));
        }
        
        return ans;
    }
}