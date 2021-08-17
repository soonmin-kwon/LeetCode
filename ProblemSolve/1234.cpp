/*********************************************
 * Replace the Substring for Balanced String *
 *********************************************/

class Solution {
public:
    int balancedString(string s) {
        int len = s.size();
        //몇개 있는지 확인
        int counts = len/4;
        unordered_map<char,int> map;
        
        //각 char 개수 저장
        for(int i=0; i<len; i++){
            map[s[i]]++;
        }
        
        int left = 0;
        int right = 0;
        int ans = INT_MAX;
        
        //Sliding Window
        //substring을 찾아야하기 때문에
        while(right < len){
            map[s[right]]--;
            
            //바꿔야 하는 개수를 만족하면서 제일 작은 길이를 찾기위해 window의 폭을 줄인다            
            while(left < len && map['Q'] <= counts && map['W'] <= counts && map['E'] <= counts && map['R'] <= counts){
                ans = min(ans, right - left + 1);
                map[s[left]]++;
                
                left++;
            }
            
            right++;
        }
        
        return ans;
    }
};