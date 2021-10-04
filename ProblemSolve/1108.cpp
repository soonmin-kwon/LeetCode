/***************************
 * Defanging an IP Address *
 ***************************/

class Solution {
public:
    string defangIPaddr(string address) {
        //.을 기준으로 분리된 문자열들 저장
        vector<string> splited;
        
        stringstream ss(address);
        string temp = "";
        
        //.을 기준으로 문자열을 나눈다
        while(getline(ss, temp, '.')){
            splited.push_back(temp);
        }
        
        string ans = "";
        
        //마지막 문자열을 제외하고 모두 [.]이 추가된다
        for(int i=0; i<3; i++){
            ans += (splited[i] + "[.]");
        }
        
        ans += splited[3];
        
        return ans;
    }
};