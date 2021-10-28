/********************************
 * Maximum Width of Binary Tree *
 ********************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        //현재 root와 몇번째 node인지 저장
        queue<pair<TreeNode*, unsigned long long int>> q;
        int ans = 0;
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            unsigned long long int leftIdx = q.front().second;
            unsigned long long int rightIdx = 0;
            int len = q.size();
            
            //len만큼 for문을 돌면 현재 depth에 있는 node들을 돌 수 있다
            for(int i=0; i<len; i++){
                pair<TreeNode*, unsigned long long int> temp = q.front();
                q.pop();
                rightIdx = temp.second;
                
                //몇번째 노드인지 지속적으로 저장
                if(temp.first -> left != NULL){
                    q.push(make_pair(temp.first -> left, 2*rightIdx + 1));
                }
                
                if(temp.first -> right != NULL){
                    q.push(make_pair(temp.first -> right, 2*rightIdx + 2));
                }
            }
            
            //width를 계산해 제일 큰 width만 저장
            ans = max(ans, (int)(rightIdx - leftIdx + 1));
        }
        
        return ans;
    }
};