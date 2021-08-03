/**************
 * Subsets II *
 **************/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //중복 제거
        set<vector<int>> s;        
        int len = nums.size();    
        vector<vector<int>> ansT;
        
        //모든 경우의 수 탐색
        for(int j = 1; j<=len; j++){
            vector<bool> check (len);
            for(int i=0; i<j; i++){
                check[i] = true;
            }
            
            do{
                vector<int> ans;
                
                for(int i=0; i<len; i++){
                    if(check[i]){
                        ans.push_back(nums[i]);
                    }
                }
                
                sort(ans.begin(), ans.end());                                
                
                s.insert(ans);
            }while(prev_permutation(check.begin(), check.end()));
        }
        ansT.push_back({});
        
        //set에 있는 벡터들 꺼내기
        for(auto it = s.begin(); it!=s.end();it++){
            ansT.push_back(*it);
        }
        
        return ansT;
    }        
};