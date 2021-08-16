/*******************************
 * Range Sum Query - Immutable *
 *******************************/

class NumArray {
public:
    vector<int> sums;
    
    //미리 sum을 계산한다
    NumArray(vector<int>& nums) : sums(nums){
        if(nums.empty()){
            return;
        }
        
        int len = sums.size();
        
        for(int i=1; i<len; i++){
            sums[i] += sums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        //처음부터 right까지인 경우
        if(left == 0){
            return sums[right];
        }

        return (sums[right] - sums[left - 1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */