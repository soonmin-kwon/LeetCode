/****************
 * Rotate Array *
 ****************/

// 참고 : Hint 3
// One line of thought is based on reversing the array (or parts of it) to obtain the desired result. 
// Think about how reversal might potentially help us out by using an example.

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if(len == 1){
            return;
        }
        
        //벡터 길이의 나머지만큼만 옮기면 된다.
        //사이클을 돌기 때문
        k = k % nums.size();
        if(k == 0){
            return;
        }
        
        //전체를 뒤집고
        reverse(nums.begin(), nums.end());
        //처음부터 옮길만큼만 뒤집으면 옮길 element들이 정렬된다.
        reverse(nums.begin(), nums.begin() + k);
        //나머지 정렬되지 않은 부분을 뒤집어 정렬
        reverse(nums.begin() +k, nums.end());
        
    }
};