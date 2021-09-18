/****************
 * Combinations *
 ****************/

class Solution {
public:
    //모든 경우의 수 조합
    void combination(vector<vector<int>>& result, vector<int>& cur, int n, int k, int start){
        //현재 만든 vector의 길이가 k면 정답에 추가한다
        if(cur.size() == k){
            result.push_back(cur);
            return;
        }
        
        //만들 수 있는 모든 수의 조합을 만든다
        //현재 추가한 수를 다음에 또 추가하지 않도록 for문의 시작 지점을 바꿔가며 진행한다
        for(int i=start; i<=n; i++){
            cur.push_back(i);            
            combination(result, cur, n, k, i + 1);
            cur.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> combinations;
        vector<vector<int>> ans;
        
        combination(ans, combinations, n, k, 1);
        return ans;
    }
};