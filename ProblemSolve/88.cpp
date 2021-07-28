/**************************************
 * Remove Duplicates from Sorted List *
 **************************************/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //nums1과 nums2 모두 오름차순으로 정렬되어 있기 때문에
        // 끝에서부터 값을 차례대로 비교하면 항상 상황에 맞는 제일 큰 값이 나온다.
        //idx3 값을 움직여 nums1의 값을 바꾼다.
        int idx3 = m + n - 1;
        //미리 값을 줄여 인덱싱을 좀 더 편하게 한다.
        m--;
        n--;
        
        //인덱싱 범위를 넘어가지 않는 선에서 확인한다.
        while(n >= 0 && m >= 0){
            //더 큰 값을 저장.
            nums1[idx3] = max(nums1[m], nums2[n]);
            
            //만약 nums1의 값이 채택됐으면 m과 idx3를 이동.
            if(nums1[m] > nums2[n]){
                m--;
                idx3--;
            }
            //만약 nums2의 값이 채택됐으면 n과 idx3를 이동.
            else{
                n--;
                idx3--;
            }
        }
        
        // n이 0이 아니면 남은 값들을 넣어준다.
        // m이 0이 아니어도 n이 0이면 nums2에 있는 값을 모두 넣은 것이기 때문에  m이 0이 아닐 때를 고려하지 않아도 된다.
        // 두 벡터 모두 정렬되어 있기 때문
        while(n >=0){
            nums1[idx3] = nums2[n];
            idx3--;
            n--;
        }        
    }
};