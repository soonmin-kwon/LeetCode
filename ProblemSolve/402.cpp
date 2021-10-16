/*******************
 * Remove K Digits *
 *******************/

class Solution {
public:
    string removeKdigits(string num, int k) {
        //stack처럼 사용
        string ans = "";
        
        //앞쪽에 최대한 작은 수를 넣는다
        //stack에 top에 있는 수가 새로 들어올 수보다 크면 바꿔줘야 더 작은 수가 된다
        //제일 앞자리부터 진행하기 때문에 그렇게 하면 가장 작은수가 만들어진다
        for(char digit : num){            
            //pop을 해야하기 때문에 비어있으면 안되고
            //ans.back() > digit을 이용해 greedy하게 진행한다
            //최대한 작은 수를 앞으로 넣어야 하기때문에 while문으로 진행한다            
            while(!ans.empty() && ans.back() > digit && k > 0){
                ans.pop_back();
                k--;
            }
            
            //digit == 0이면서 ans가 empty면 push를 하면 안된다
            //그 외에는 push를 해도 된다
            if(!ans.empty() || digit != '0'){
                ans.push_back(digit);
            }
        }
        
        //최대한 작은 수를 넣었음에도 k번 제거하지 않은경우
        //비교적 큰 수인 뒤에서부터 제거한다
        while(!ans.empty() && k){
            k--;
            ans.pop_back();
        }
        
        return ans=="" ? "0" : ans;
    }
};