/********************************
 * Subarray Sums Divisible by K *
 ********************************/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int len = nums.size();
        int sum = 0;
        int ans = 0;
        
        vector<int> prefix(k, 0);
        
        //nums[0]가 k로 나눠떨어지는 경우도 체크
        prefix[0] = 1;
        
        for(int i=0; i<len; i++){                        
            sum += nums[i];
            
            //sum이 음일 경우를 대비해 + k를 한다
            //-1 % 5 => 0 * 5 + (-1) or -1 * 5 + (4)
            //예를 들어 i에서 prefix[4], j에서 prefix[4]가 나오면 i와 j사이에는
            //k로 나눠떨어지는 subarray가 존재
            //나머지 값마다 개수를 세주고 다시 그 나머지 값이 등장하면
            //그 개수가 0~i번째까지 모든 값을 더했을 때 같은 나머지가 나온 회수를 의미하므로
            //그 회수만큼 더해주면 0 ~ i번째까지의 모든 subarray의 수를 구할 수 있다
            ans += prefix[(sum % k + k) % k];
                        
            prefix[(sum % k + k) % k]++;
        }

        return ans;
    }
};