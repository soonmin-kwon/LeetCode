/**********************************************
 * Convert Sorted Array to Binary Search Tree *
 **********************************************/

class Solution {
public:
    //재귀로 트리 만들기
    TreeNode* makeBST(vector<int>& nums, int start, int end){
        //크로스 되면 null
        if(end <= start){
            return NULL;
        }
        
        //중간점을 잡는다.
        int mid = (end - start) / 2 + start;
        
        //현재 노드를 트리에 추가
        TreeNode* root = new TreeNode(nums[mid]);
        
        //루트를 기준으로 왼쪽을 만든다.
        root -> left = makeBST(nums, start, mid);
        
        //오른쪽 만들기
        root -> right = makeBST(nums, mid+1, end);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeBST(nums, 0, nums.size());
    }
};