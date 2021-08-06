/************************************
 * N-ary Tree Level Order Traversal *
 ************************************/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {        
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }        
        
        //BFS 준비
        queue<pair<Node*,int>> q;
        vector<int> temp;
        vector<Node*> children;
        Node* child;
        int depth;
        int len;
        
        q.push(make_pair(root, 1));                
        
        while(!q.empty()){
            child = q.front().first;
            depth = q.front().second;
            q.pop();
            
            //children이 있으면 q에 넣는다
            len = (child -> children).size();
            if(len != 0){                
                children = child -> children;
                
                for(int i=0; i<len; i++){
                    q.push(make_pair(children[i], depth + 1));
                }
            }
            
            //현재 depth와 답 벡터의 크기를 비교해 값을 넣어준다
            
            //현재 depth - 1이 ans.size()와 다르면 ans에 넣어준다. 
            //depth가 2면 ans[1]에 들어가야하기 때문
            if(depth -1 != ans.size()){
                ans.push_back(temp);
                temp.clear();
                temp.push_back(child -> val);
            }
            else{ //depth가 ans.size()와 같으면 같은 층에 있는 node들의 val을 벡터에 저장
                temp.push_back(child -> val);
            }
            
        }
        
        //남아있는 벡터 추가
        if(!temp.empty()){
            ans.push_back(temp);
        }
        
        return ans;
    }
};