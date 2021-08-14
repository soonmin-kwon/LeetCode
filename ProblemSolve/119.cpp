/************************
 * Pascal's Triangle II *
 ************************/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1);
        int c;
        if(rowIndex == 0){
            return {1};
        }
        
        ans[0] = 1;
        
        //한 줄은 nC0 , nC1, nC2, nC3... nCn
        //nC1 = n / 1
        //nC2 = n * (n - 1) / 2 * 1
        //nC3 = n * (n - 1) * (n - 2) / 3 * 2 * 1
        //nC4 = nC3 * (n - 3) / 4
        //nCr = nCr-1 * (n - r + 1) / r
        //ans[i] = nCi, rowIndex = n, i = r
        for(int i= 1; i<=rowIndex; i++){            
            //나누기 전에 오버플로우 방지로 1LL 추가
            ans[i] = 1LL * ans[i-1] * (rowIndex - i + 1) / i;            
        }
        
        return ans;
    }
};