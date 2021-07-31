/*********************************
 * Intersection of Two Arrays II *
 *********************************/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {     
        vector<int> ans;
        //정렬해서 비교
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int pointer1 = 0;
        int pointer2 = 0;
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        //한 벡터를 전부 진행하면 끝
        while(len1 > pointer1 && len2 > pointer2){            
            if(nums1[pointer1] > nums2[pointer2]){
                pointer2++;
            }
            else if(nums1[pointer1] < nums2[pointer2]){
                pointer1++;
            }
            else{
                ans.push_back(nums1[pointer1]);
                pointer1++;
                pointer2++;
            }
        }
     
        return ans;
    }
};