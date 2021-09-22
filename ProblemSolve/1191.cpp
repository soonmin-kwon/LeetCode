/*******************************
 * K-Concatenation Maximum Sum *
 *******************************/

//참고 : https://leetcode.com/problems/k-concatenation-maximum-sum/discuss/382885/Short-and-concise-O(N)-C%2B%2B-solution
//     : https://leetcode.com/problems/k-concatenation-maximum-sum/discuss/383302/C%2B%2B-clean-code-beat-97-with-detailed-explanation

#define mod 1000000007

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int len = arr.size();
        //주어진 arr의 합을 구한다
        long long int arrSum = accumulate(arr.begin(), arr.end(), 0);
        
        //Kadane 알고리즘
        int tempSum = 0;
        int maxPreSufSubarrSum = 0;
                    
        //k = 1 인 경우 그냥 kadane 알고리즘 한번 진행하면 된다.
        //k = 2 이상인 경우 arrSum 값에 따라 경우가 나뉜다
        //우선 arr를 하나 더 이어붙여서 prefixMaxSum + suffixMaxSum을 구한다        
        //arrSum > 0 인 경우 : 3번째 arr부터는 arrSum 값만큼 계속 증가한다
        //arrSum <= 0 인 경우 : prefixMaxSum + suffixMaxSum이 정답이 된다
        
        //k가 1이면 한번만 진행하도록, k가 2 이상인 경우에는 2번만 진행하도록 한다
        for (int i = 0; i < min(2, k) * len; i++) {
            tempSum = max(arr[i % len], tempSum + arr[i % len]);
            maxPreSufSubarrSum = max(tempSum, maxPreSufSubarrSum);
	    }

        //만약 arr가 모두 음수이면 0이 정답이 될 것이다
        //위에서 말한 arrSum <= 0 인 경우에는 maxPreSufSubarrSum이 정답이 된다.
        //arrSum > 0인 경우에는 추가된 arr 중에 남아 있는 개수가 k - 2개이고 arrSum * (k - 2)만큼 maxPreSufSubarrSum에 더해주면 된다.        
        return max({0, maxPreSufSubarrSum, (int)(maxPreSufSubarrSum + arrSum * max(0, k-2) % mod)}) % mod;
    }
};