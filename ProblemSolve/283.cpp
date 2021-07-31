/***************
 * Move Zeroes *
 ***************/

class Solution {
public:
    // STL : stable_partition    
    // lambda 없이 구현
    static bool isZero(int num){
        return num;
    }
    
    void moveZeroes(vector<int>& nums) {                
        stable_partition(nums.begin(), nums.end(), isZero);
    }
    
    // lambda로 구현
    void moveZeroes(vector<int>& nums) {                
        stable_partition(nums.begin(), nums.end(), 
                         [](int i){
                             return i;
                         });
    }
    
    // Solution 2
    void moveZeroes(vector<int>& nums) {
        int nonZeroIdx = 0;
        int len = nums.size();
        
        //벡터를 쭉 돌면서 0이 아니면 앞에서 부터 채워넣는다.
        for(int i=0; i<len; i++){
            if(nums[i]){
                nums[nonZeroIdx] = nums[i];
                nonZeroIdx ++;
            }
        }
        
        //위 for문에서 0이 아닌 모든 원소들을 집어넣었고 그 뒤에 남은 만큼은 0으로 채워줘야 함.
        for(int i=nonZeroIdx; i<len; i++){
            nums[i] = 0;
        }
    }
};