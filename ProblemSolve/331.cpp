/**************************************************
 * Verify Preorder Serialization of a Binary Tree *
 **************************************************/

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int len = preorder.size();
        int count = 1;
        
        if(len == 0){
            return false;
        }                
        
        for(int i=1; i<len; i++){
            if(count < 1){
                return false;
            }
            
            //,로 분리하기 때문에 ,이전 값을 확인해서 NULL인지 확인
            if(preorder[i] == ','){
                //NULL이 나올 수 있는 개수를 센다
                //한 parent당 두 개의 child가 생성될 수 있다
                //한 parent는 어떤 노드의 child가 되기 때문에 count를 +2가 아니라 +1로 계산한다
                count = preorder[i-1] != '#' ? count + 1 : count - 1;
            }
        }
        
        //마지막 input 확인
        count = preorder[len-1] != '#' ? count + 1 : count - 1;
        
        //맞아 떨어지면 true
        return (count == 0);
    }
};