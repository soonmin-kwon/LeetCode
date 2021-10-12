/********************************
 * Guess Number Higher or Lower *
 ********************************/

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {        
        unsigned int left = 1;
        unsigned int right = n;
        unsigned int target = (left + right) / 2;
        int res = guess(target);
        
        //전형적인 binary search
        while(res != 0){
            //res가 -1인 경우 맞춰야하는 값이 target 값보다 작다
            //즉, right 경계를 움직인다
            if(res == -1){
                right = target - 1;
                target = (left + right) / 2;
            }
            //res가 1인 경우 맞춰야하는 값이 target 값보다 크다
            //즉, left 경계를 움직인다
            else if(res == 1){
                left = target + 1;
                target = (left + right) / 2;
            }
            
            res = guess(target);
        }
        
        return target;
    }
};