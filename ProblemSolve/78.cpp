/***********
 * Subsets *
 ***********/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //기초 작업
        vector<vector<int>> ans;
        ans.push_back({});
        int len = nums.size();
        vector<int> temp;
        
        //모든 길이의 subset을 찾아야 하기 때문에 for문으로 1부터 길이를 늘려나감
        for(int j = 1; j<=len; j++){
            vector<bool> check (len);
            
            //check 벡터에 true를 길이만큼 추가
            for(int i=0; i<j; i++){
                check[i] = true;
            }
            
            //check 벡터를 prev_permutation으로 돌리면서 subset을 찾는다
            do{
                temp.clear();
                
                for(int i=0; i<len; i++){
                    //check 벡터에서 true로 체크되어있는 idx만 임시 벡터에 추가
                    if(check[i]){
                        temp.push_back(nums[i]);
                    }
                }
                
                //정답 벡터에 추가
                ans.push_back(temp);
            }while(prev_permutation(check.begin(), check.end()));
        }
        
        return ans;
    }
};