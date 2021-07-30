/********
 * 3Sum *
 ********/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> ans;        
        if(len < 3){
            return ans;
        }
        vector<int> temp(3);
        sort(nums.begin(), nums.end());        
        int left, right, fix, sum;
        
        //고정점을 하나 잡고 고정점보다 뒤의 인덱스에서 2Sum을 한다.
        //정렬한 벡터이기 때문에 겹치는 값들을 스킵하면서 진행해 진행 속도를 높인다.
        
        for(int i=0; i<len; i++){
            //고정점은 항상 제일 작은 값인데 가장 작은 값이 양수이면 절대로 0이 나올 수 없다.
            //loop을 그만 돈다.
            if(nums[i] > 0){
                break;
            }
            
            //고정점이 전과 같으면 3Sum을 찾지 않아도 된다. skip
            if(i > 0 && nums[i-1] == nums[i]){
                continue;
            }
            
            left = i+1;
            right = len -1;
            fix = nums[i];
            
            //서로 교차되면 안된다.
            while(left < right){
                sum = fix + nums[left] + nums[right];                
                if(sum == 0){
                    //원하는 값이 나오면 벡터에 넣어주고
                    temp[0] = fix;
                    temp[1] = nums[left];
                    temp[2] = nums[right];
                    ans.push_back(temp);
                    
                    //정답이 되는 값들을 저장한 뒤에
                    int prevLeft = nums[left], prevRight = nums[right];
                    
                    // 같은 값들이 있으면 싹 스킵해준다. 같은 조합이 나올 수 있다.
                    while(left < right && nums[left] == prevLeft){
                        left++;
                    }
                    
                    while(left < right && nums[right] == prevRight){
                        right--;
                    }
                }
                //정렬되어 있기 때문에 0보다 크면 오른쪽에서 왼쪽으로 한칸 가야만 하고
                //0보다 작으면 왼쪽에서 오른쪽으로 한칸 가야만 한다.
                else if(sum > 0){
                    right--;
                }
                else if(sum < 0){
                    left++;
                }
            }
        }
        
        return ans;        
    }
};