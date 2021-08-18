/************************
 * Boats to Save People *
 ************************/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        //그리디하게 선택하기 위해 정렬
        sort(people.begin(), people.end());
        
        int len = people.size();
        if(len == 1){
            return 1;
        }
        
        int left = 0;
        int right = len - 1;
        int ans = 0;
        bool temp = 0;
        
        //가장 무거운 사람과 가장 가벼운 사람을 같이 태우는 게 가장 효율적인 방법
        //가장 무거운 사람만 탈 수 있으면 가장 무거운 사람만 태운다
        //left에 있는 사람, right에 있는 사람을 태웠으면 left++, right--해준다
        while(left <= right){
            ans++;
            if(people[left] + people[right] <= limit){
                left++;
            }
            right--;
        }
        
        return ans;
    }
};