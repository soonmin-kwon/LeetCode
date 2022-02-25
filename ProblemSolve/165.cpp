/***************************
 * Compare Version Numbers *
 ***************************/

class Solution {
public:
    vector<int> split(string input, char delimiter){
        vector<int> output;
        stringstream ss(input);
        string temp;
        
        while(getline(ss, temp, delimiter)){
            output.push_back(stoi(temp));
        }
        
        return output;
    }
    
    int compareVersion(string version1, string version2) {
        vector<int> revisionV1 = split(version1, '.');
        vector<int> revisionV2 = split(version2, '.');
        
        int idxV1 = 0, idxV2 = 0;
        int lenV1 = revisionV1.size();
        int lenV2 = revisionV2.size();
        
        while(idxV1 < lenV1 && idxV2 < lenV2){
            int rev1 = revisionV1[idxV1++];
            int rev2 = revisionV2[idxV2++];
            if(rev1 > rev2){
                return 1;
            }
            else if(rev2 > rev1){
                return -1;
            }
        }
        
        if(lenV1 == lenV2)
            return 0;
        
        if(idxV1 >= lenV1){
            while(idxV2 < lenV2){
                int rev2 = revisionV2[idxV2++];
                if(rev2 > 0){
                    return -1;
                }
            }
            return 0;
        }
        else if(idxV2 >= lenV2){
            while(idxV1 < lenV1){
                int rev1 = revisionV1[idxV1++];
                if(rev1 > 0){
                    return 1;
                }
            }
            return 0;
        }
        
        return 0;
    }
};