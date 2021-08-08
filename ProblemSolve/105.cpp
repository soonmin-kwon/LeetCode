/*************************************************************
 * Construct Binary Tree from Preorder and Inorder Traversal *
 *************************************************************/

class Solution {
public:
    int idx = 0;
    unordered_map<int, int> index;
    
    //정답 트리를 만든다.
    TreeNode* makeTree(vector<int>& preorder, int left, int right) {
        //범위가 크로스되면 리턴
        if(left > right){
            return NULL;
        }
        
        //preorder에서 root값을 찾는다
        int val = preorder[idx++];
        //root값을 갖도록 트리 생성
        TreeNode* root = new TreeNode(val);
        
        //index[val]은 val이 inorder에서 왼쪽, 오른쪽을 나누는 기준이 된다
        root -> left = makeTree(preorder, left, index[val] - 1);
        root -> right = makeTree(preorder, index[val] + 1, right);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int right = preorder.size() - 1;
        
        //inorder를 참고해 preorder에서 root값이 inorder 기준 몇 번째 idx인지 찾기 쉽게 한다
        for(int i=0; i<=right; i++){
            index[inorder[i]] = i;
        }

        return makeTree(preorder, 0, right);
    }
};