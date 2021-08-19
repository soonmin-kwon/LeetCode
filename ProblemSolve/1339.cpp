/*******************************************
 * Maximum Product of Splitted Binary Tree *
 *******************************************/

class Solution {
public:
    long long int sum = 0;
    long long int ans = 0;
    
    //모든 노드의 val 값의 합을 구한다    
    long long int calSum(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        return root-> val + calSum(root->left) + calSum(root->right);
    }
    
    //정답을 갱신하고, 모든 node를 돌면서 가능한 최대값을 구한다
    long long int calAns(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        //left sub tree sum
        long long int left = calAns(root -> left);
        //right sub tree sum
        long long int right = calAns(root -> right);
        
        //현재 노드의 left, right subtree sum sum을 전체 sum에서 빼면 left, right subtree를 cut하고 남은 tree의 sum만 남는다
        ans = max(ans, max(left * (sum - left), right * (sum - right)));
        
        //sum
        return left + right + root -> val;
    }
    
    int maxProduct(TreeNode* root) {
        long long int res = INT_MIN;
        sum = calSum(root);
        calAns(root);
        
        return ans % 1000000007;
    }
};