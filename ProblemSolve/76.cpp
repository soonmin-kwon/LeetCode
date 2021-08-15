/****************************
 * Minimum Window Substring *
 ****************************/

class Solution {
public:
    string minWindow(string s, string t) {
        //검사할 이유가 없는 경우들
        if(s.size() == 0 || t.size() == 0 || t.size() > s.size()){
            return "";
        }
        
        int len = s.size();
        int len2 = t.size();
        
        //찾아야 되는 모든 char 저장
        unordered_map<char,int> character;
        //찾아야 하는 만큼 다 찾았는지 확인할 때 이용
        unordered_map<char,int> check;
        
        //t에 들어있는 모든 char개수 저장
        for(int i=0; i<len2; i++){
            character[t[i]] += 1;
        }
        
        int left = 0, right = 0;
        int leftR = 0, rightR = 0;
        int count = 0;
        int distance = INT_MAX;
        //서로 다른 원소들 개수
        int checkCount = character.size();
                
        while(right < len){
            check[s[right]]++;
            
            //s[right]가 t에 들어있으면서 만족해야하는 개수를 채우면 count를 늘린다
            if(character.find(s[right]) != character.end() && character[s[right]] == check[s[right]]){
                count++;
            }
            
            //window 폭 증가
            right++;
            
            //찾아야 하는 모든 char을 찾았으면
            while(count == checkCount && left < right){
                //거리를 갱신
                if(distance > right - left){
                    distance = right - left;
                    //최종적으로 제일 작은 거리의 두 idx정보 저장
                    leftR = left;
                    rightR = right;
                }
                
                check[s[left]]--;
                
                //s[left]가 t에 들어있으면서 character[s[left]]가 check[s[left]]보다 크면
                //위에서 -1 된 원소라는 뜻이기 때문에 count를 줄여준다
                if(character.find(s[left]) != character.end() && character[s[left]] > check[s[left]]){
                    count--;
                }
                
                //window 폭 감소
                left++;
            }
        }
        
        return s.substr(leftR, rightR - leftR);
    }
};