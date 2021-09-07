/*****************************
 * Find the Duplicate Number *
 *****************************/

//참고 : https://leetcode.com/problems/find-the-duplicate-number/solution/

class Solution {
public:
    //Time : O(n), Space : O(n) -> 조건에 부합 x
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> count;
        
        for(auto x : nums){
            if(count.find(x) != count.end()){
                return x;
            }
            
            count[x]++;
        }
        
        return 0;
    }
    
    //Time : O(n), Space : O(1) -> 조건에 부합 o
    //Solution 7     
    //1 <= nums[i] <= n, nums.length == n + 1
    //nums[i]의 값을 하나의 주소 값이라 가정하면
    //duplicate한 값이 있으면 다른 i에서 같은 주소를 참조하게 되고, linked list의 cycle처럼 cycle이 생기게 된다
    //cycle이 생기는 nums[i]값이 duplicate한 값이다
    
    int findDuplicate(vector<int>& nums) {
        //cycle인지 아닌지 확인하는 tortoise & hare 알고리즘
        int tortoise = nums[0];
        int hare = nums[0];
        
        //cycle인지 확인
        do{            
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        }while(hare != tortoise);
        
        tortoise = nums[0];
        
        //cycle이 생기는 지점을 찾는다
        while(tortoise != hare){
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        
        return hare;
    }
};