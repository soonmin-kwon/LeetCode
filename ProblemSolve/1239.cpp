/******************************************************************
 * Maximum Length of a Concatenated String with Unique Characters *
 ******************************************************************/

class Solution {
public:
    int ans = 0;
    
    //Brian Kernighan's Algorithm
    int countSetBits(int n){
        int count = 0;

        //ex) 9
        //9 & 8 -> 1001 & 1000 = 1000
        //8 & 7 -> 1000 & 0111 = 0000
        while(n){
            n &= (n-1);
            count++;
        }

        return count;
    }
    
    void dfs(int index, int mask, vector<int>& masks){
        //최대 길이 저장
        ans = max(ans, countSetBits(mask));
        
        //모든 index 검색
        for(int i=index; i<masks.size(); i++){
            //서로 겹치는 char가 없는 경우
            if((masks[i] & mask) == 0){
                //다음 순서부터 검색, 새로운 mask 생성
                dfs(i + 1, masks[i] | mask, masks);
            }
        }
    }
    
    int maxLength(vector<string>& arr) {
        
        vector<int> masks;
        int len = arr.size();
        int len2;
        int mask = 0;
        int temp;
        
        for(int i=0; i<len; i++){
            mask = 0;
            len2 = arr[i].size();
            
            //알파벳 순서에 따라 bit masking
            for(int j=0; j<len2; j++){
                mask |= 2 << (arr[i][j] - 'a');
            }
            //1의 개수를 세고
            temp = countSetBits(mask);
            
            //arr[i]의 길이와 다르면 스스로 겹치는 캐릭터를 가지고 있다는 뜻이기 때문에 스킵            
            if(temp != len2){
                continue;
            }
            
            masks.push_back(mask);
        }
        dfs(0, 0, masks);
        
        return ans;
    }
};