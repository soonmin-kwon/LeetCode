/*********************************
 * Complex Number Multiplication *
 *********************************/

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {        
        //num1의 정수부, num2의 정수부, num1의 복소수부, num2의 복소수부
        string nums1, nums2, complex1, complex2;
        int idx = 0;
        
        //정수부 분리
        while(num1[idx] != '+'){
            nums1 += num1[idx];
            idx++;
        }
        
        //복소수부 분리
        complex1 = num1.substr(idx + 1, num1.size() - idx - 2);
        idx = 0;
        
        //정수부 분리
        while(num2[idx] != '+'){
            nums2 += num2[idx];
            idx++;
        }
        
        //복소수부 분리
        complex2 = num2.substr(idx + 1, num2.size() - idx - 2);
        
        //(a + ib) x (c + id) = ac + i^2bd + i(bc + ad) = ac - bd + i(bc + ad)
        int a = stoi(nums1);
        int b = stoi(complex1);
        int c = stoi(nums2);
        int d = stoi(complex2);
                
        string ans = to_string(a*c - b*d) + "+" + to_string(b*c + a*d) + "i";
        
        return ans;
    }
};