/***********************************
 * Maximum Product of Word Lengths *
 ***********************************/

//참고 : https://leetcode.com/problems/maximum-product-of-word-lengths/discuss/1233648/Short-and-Easy-Solution-w-Explanation-or-C%2B%2B-using-Bitset-and-Bit-masking-or-Beats-100

class Solution {
public:    
    int maxProduct(vector<string>& words) {
        int len = words.size();
        int ans = 0;
        vector<int> mask(len);
        
        for(int i=0; i<len; i++){
            //알파벳에 따라 bit masking
            //mask[i]는 words[i]의 정보를 저장
            for(int j = 0; j<words[i].size(); j++){
                mask[i] |= (1 << (words[i][j] - 'a'));
            }
            
            //words[i]와 words[j]를 확인해
            //서로 다른 알파벳으로만 이뤄져있으면 &연산은 0이 나온다
            for(int j=0; j<i; j++){
                if((mask[i] & mask[j]) == 0){
                    ans = max(ans, (int)(words[i].size() * words[j].size()));
                }
            }
        }
        
        return ans;
    }
};