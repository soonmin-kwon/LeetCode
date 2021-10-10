/*************************************************
 * Sum of Absolute Differences in a Sorted Array *
 *************************************************/

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int len = nums.size();
        
        vector<int> ans(len);
        ans[0] = (sum - (nums[0] * (len)));
                
        //nums[1] - nums[0] = N1
        //nums[2] - nums[1] = N2
        //...
        //nums[n] - nums[n-1] = Nn라고 하면
        //ans[0] = (n-1)N1 + (n-2)N2 + (n-3)N3 + ... + Nn이고
        //ans[1] = N1 + (n-2)N2 + (n-3)N3 + ... + Nn,
        //ans[2] = N1 + 2N2 + (n-3)N3 + ... + Nn
        //ans[3] = N1 + 2N2 + 3N3 + ... + Nn
        //ans[n] = N1 + 2N2 + 3N3 + ... + nNn 이다
        
        //즉, ans[1] = ans[0] + (2 - n)N1
        //ans[2] = ans[1] + (4 - n)N2
        //...
        //ans[n] = ans[n-1] + (2*n - n)Nn이 된다        
        for(int i=1; i<nums.size(); i++){
            ans[i] = ans[i-1] + (nums[i] - nums[i-1]) * (2 * i - len);
        }
        
        return ans;
    }
};