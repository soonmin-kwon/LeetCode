/********************
 * House Robber III *
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
    public int Max(int a, int b){
        return a >= b ? a : b;
    }
    //DFS 방식으로 트리 순회
    public int[] CalMaxMoney(TreeNode root){
        if(root == null){
            return new int[2];
        }
        
        int[] left = CalMaxMoney(root.left);
        int[] right = CalMaxMoney(root.right);
        
        int choose = root.val + left[1] + right[1]; //현재 노드를 훔친 경우. 다음 노드는 훔치지 못함.
        int noChoose = Max(left[0], left[1]) + Max(right[0], right[1]); //현대 노드를 훔치지 않는 경우. 
                                                                        //다음 노드를 훔쳤을 때와 훔치지 않았을 때 중 더 큰 값 선택        
        return new int[2]{choose, noChoose};
    }
    
    public int Rob(TreeNode root) {
        int[] ansArr = CalMaxMoney(root);
        
        return Max(ansArr[0], ansArr[1]);
    }
}