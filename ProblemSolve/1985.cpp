/*********************************************
 * Find the Kth Largest Integer in the Array *
 *********************************************/

class Solution {
public:
    //string으로 담겨있는 정수를 비교
    static bool compare(string& a, string& b){
        int lenA = a.size();
        int lenB = b.size();
        
        //두 string의 길이가 다르면 무조건 길이가 긴 쪽이 큰 수
        if(lenA == lenB){
            //같은 자리수를 비교, 제일 높은 자리수부터 비교해 바로 바로 판단할 수 있게 한다
            for(int i=0; i<lenA; i++){
                if(a[i] == b[i]){
                    continue;
                }
                else{
                    return a[i] > b[i];
                }
            }
        }
        
        return lenA > lenB;
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), compare);
        
        return nums[k - 1];
    }
};