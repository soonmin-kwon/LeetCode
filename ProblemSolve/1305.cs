/*******************************************
 * All Elements in Two Binary Search Trees *
 *******************************************/

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
    public void GetElementsList(TreeNode root, ref List<int> list){
        if(root == null){
            return;
        }
        
        if(root.left != null){
            GetElementsList(root.left, ref list);
        }
        
        list.Add(root.val);
        
        if(root.right != null){
            GetElementsList(root.right, ref list);
        }
        
        return;
    }
    
    public IList<int> GetAllElements(TreeNode root1, TreeNode root2) {
        List<int> root1List = new List<int>();
        List<int> root2List = new List<int>();
        List<int> ans = new List<int>();
        
        GetElementsList(root1, ref root1List);
        GetElementsList(root2, ref root2List);
        
        int idx1 = 0, idx2 = 0, len1 = root1List.Count, len2 = root2List.Count;
        
        while(idx1 < len1 && idx2 < len2){
            if(root1List[idx1] >= root2List[idx2]){
                ans.Add(root2List[idx2]);
                idx2++;
            }
            else{
                ans.Add(root1List[idx1]);
                idx1++;
            }
        }
        
        while(idx1 < len1){
            ans.Add(root1List[idx1++]);            
        }
        
        while(idx2 < len2){
            ans.Add(root2List[idx2++]);
        }
        
        return ans;        
    }
}