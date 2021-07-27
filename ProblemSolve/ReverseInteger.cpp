class Solution {
public:
    int reverse(int x) {        
	    int lim = INT_MAX;		
        //예외 처리
	    if (x == 0 || x == INT_MAX || x == INT_MIN) {
    		return 0;
    	}

        //입력 범위, 조건에 따라 다른 방식으로 확인하기 위한 과정
    	char sign = '+';
    	string temp = "";
    	string check = to_string(lim);
    	string check2 = check;        
    	check2[9] = '8';

        //음수 체크
    	if (x < 0) {
    		x *= -1;
    		sign = '-';
    	}

        //string으로 변환
    	while (x != 0) {
    		temp += to_string(x % 10);
    		x = x / 10;
    	}
        
        //위에서 만든 check, check2와 비교하면서 범위에서 벗어나면 0을, 
        //범위 안에 있으면 루프를 멈춘다.
    	if (temp.size() == 10 && temp[0] - '0' >= 2) {
    		if (sign == '-') {
    			for (int i = 0; i < 10; i++) {
    				if (temp[i] - '0' > check[i] - '0') {
					    return 0;
				    }
                    else if (temp[i] - '0' < check[i] - '0') {
					    break;
				    }
			    }
		    }
		    else {
    			for (int i = 0; i < 10; i++) {
    				if (temp[i] - '0' > check2[i] - '0') {
    					return 0;
    				}
                    else if (temp[i] - '0' < check[i] - '0') {
				    	break;
				    }
    			}
    		}
    	}

        //부호까지 출력
    	if (sign == '-') {
    		temp = '-' + temp;
    	}
        
        return stoi(temp);
    }
};