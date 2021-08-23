/******************
 * Largest Number *
 ******************/

class Solution {
public:
    //Compare 함수
    const static bool compare(int a, int b){
        string aT = to_string(a);
        string bT = to_string(b);
        
        //a가 30, b가 3일경우에 30 > 3이라 30, 3으로 정렬되지만 303보다 330이 크다
        //a + b, b + a로 비교하면 위같은 경우 해결
        return aT + bT > bT + aT;
    }
    
    string largestNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end(), compare);
        string ans = "";
                
        for(int i=0; i<nums.size(); i++){
            ans += to_string(nums[i]);
        }
        
        //제일 큰 수가 앞으로 오는데 그 수가 0이면 무조건 0이다
        if(ans[0] == '0'){
           return "0";
        }
           
        return ans;
    }
};