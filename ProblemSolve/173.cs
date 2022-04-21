/*******************************
 * Binary Search Tree Iterator *
 *******************************/

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

public class BSTIterator {
    public Stack<TreeNode> st = new Stack<TreeNode>();
    TreeNode curNode = null;
    
    public BSTIterator(TreeNode root) {
        PushAllNodeToStack(root);
    }
    
    public int Next() {
        curNode = st.Pop();
        PushAllNodeToStack(curNode.right);
        return curNode.val;
    }
    
    public bool HasNext() {
        return st.Count > 0;
    }
    
    private void PushAllNodeToStack(TreeNode root){
        while(root != null){
            st.Push(root);
            root = root.left;
        }
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.Next();
 * bool param_2 = obj.HasNext();
 */