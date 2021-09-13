/******************************
 * Maximum Number of Balloons *
 ******************************/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        //text 문자열에 있는 char의 개수를 센다
        unordered_map<char, int> counts;
        
        for(auto ch : text){
            counts[ch]++;
        }
        //가능한 balloon의 개수를 세야하기 때문에 b, a, n의 개수와 비교하기 쉽도록 두개가 나오는 문자열은 나눠준다
        counts['l'] /= 2;
        counts['o'] /= 2; 
        
        //b, a, l, o, n의 개수 중에 가장 작은 값만큼 balloon 문자를 만들 수 있다
        return min({counts['a'], counts['b'], counts['l'], counts['o'], counts['n']});
    }
};