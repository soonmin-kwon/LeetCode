/*************************************
 * Binary Tree Level Order Traversal *
 *************************************/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        //예외처리
        if(root == NULL){
            return ans;
        }
        
        vector<int> temp;
        TreeNode* node;
        int depth;
        
        //BFS 준비
        queue<pair<TreeNode*, int>> q;        
        q.push(make_pair(root, 1));        
      
        while(!q.empty()){
            node = q.front().first;
            depth = q.front().second;
            q.pop();
            
            //left -> right 순으로 넣어야 하기 때문에 left 먼저
            if(node->left){
                q.push(make_pair(node->left, depth+1));
            }
            
            if(node->right){        
                q.push(make_pair(node->right, depth+1));                
            }
            
            //depth에 맞게 넣어줘야하기 때문에 depth와 ans의 길이를 비교해 넣는다.
            if(depth - 1 != ans.size()){
                //지금까지 모은 벡터를 넣어주고
                ans.push_back(temp);
                //지운 다음
                temp.clear();
                //현재 노드의 값을 새로 넣어준다.
                temp.push_back(node->val);
            }
            else{
                //아직 같은 층을 순회하고 있으면 임시 벡터에 추가
                temp.push_back(node->val);
            }
        }
        
        //남은 벡터가 있으면 추가
        if(!temp.empty()){
            ans.push_back(temp);
        }
        
        return ans;
    }
};