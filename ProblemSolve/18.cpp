/********
 * 4Sum *
 ********/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int len = nums.size();
        //4sum이 불가능한 경우
        if(len < 4){
            return ans;
        }
                
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<len-3; i++){
            //target이 절대 만들어 질 수 없다
            if(target <= 0 && nums[i] > 0){
                break;
            }
            
            //가장 작은 4개를 더했을 때 target보다 크면 절대 target을 만들 수 없다
            if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target){
                break;
            }
            
            //중복 스킵
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            
            for(int j=i+1; j<len-2; j++){
                //j기준으로 가장 작은 4개를 더했을 때 target보다 크면 절대 target을 만들 수 없다
                if(nums[i] + nums[j] + nums[j+1] + nums[j+2] > target){
                    break;
                }
                
                //중복 스킵
                if(j > i + 1 && nums[j] == nums[j-1]){
                    continue;
                }
                
                //i와 j를 기준으로 잡고 나머지 두 수를 찾는다
                int left = j + 1;       //i와 j를 제외하고 가장 작은 수
                int right = len - 1;    //선택할 수 있는 가장 큰 수
                
                while(left < right){
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];                    
                    //target을 만들 수 있으면 정답에 추가
                    if(sum == target){
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        int prevLeft = nums[left];
                        int prevRight = nums[right];
                        
                        //중복 스킵
                        while(left < right && nums[left] == prevLeft){
                            left++;
                        }
                        
                        //중복 스킵
                        while(left < right && nums[right] == prevRight){
                            right--;
                        }
                    }
                    //sum이 target보다 크면 sum이 작아져야 하므로 right의 위치를 당겨서 작은 수를 가리키도록 한다
                    else if(sum > target){
                        right--;
                    }
                    //sum이 target보다 작으면 sum이 커져야 하므로 left의 위치를 밀어서 큰 수를 가리키도록 한다
                    else{
                        left++;
                    }
                }
            }
        }
        
        return ans;
    }
};