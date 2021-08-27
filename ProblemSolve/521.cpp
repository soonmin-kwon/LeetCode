/**********************************
 * Longest Uncommon Subsequence I *
 **********************************/

class Solution {
public:
    int findLUSlength(string a, string b) {
        //두 문자열이 같으면 서로 subsequence가 된다
        if(a == b){
            return -1;
        }
        
        //두 문자열이 다른경우 한쪽이 더 길게되면 그 긴 문자열은 짧은 문자열의 subsequence가 될 수 없다
        //두 문자열이 다르면서 길이가 같으면 절대 서로 subsequence가 될 수 없다
        return max(b.size(), a.size());
    }
};