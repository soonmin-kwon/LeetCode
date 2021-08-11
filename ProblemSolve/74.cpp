/**********************
 * Search a 2D Matrix *
 **********************/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int len = matrix.size();
        int len2 = matrix[0].size() - 1;
        int row = 0;
        
        //몇번째 row에 있을 수 있는지 확인
        for(int i=0; i<len; i++){
            if(target == matrix[i][len2]){
                return true;
            }            
            else if(target < matrix[i][len2]){
                row = i;
                break;
            }
        }
        
        int left = 0;
        
        //target이 있을수 있는 row를 binary search
        while(left <= len2){
            int mid = (left + len2)/2;
            
            if(matrix[row][mid] == target){
                return true;
            }            
            else if(matrix[row][mid] > target){
                len2 = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        
        return false;
    }
};