/***************************
 * Compare Version Numbers *
 ***************************/

public class Solution {
    public int CompareVersion(string version1, string version2) {
        int idxV1 = 0, idxV2 = 0;
        string[] revisionV1 = version1.Split(".");
        string[] revisionV2 = version2.Split(".");
        
        while(idxV1 < revisionV1.Length && idxV2 < revisionV2.Length){
            int rev1 = int.Parse(revisionV1[idxV1++]);
            int rev2 = int.Parse(revisionV2[idxV2++]);
            if(rev1 < rev2){
                return -1;
            }
            else if(rev1 > rev2){
                return 1;
            }            
        }
        
        if(revisionV1.Length == revisionV2.Length){
            return 0;
        }
        
        if(idxV1 >= revisionV1.Length){
            while(idxV2 < revisionV2.Length){
                int rev2 = int.Parse(revisionV2[idxV2++]);
                if(rev2 > 0){
                    return -1;
                }
            }
            return 0;
        }
        else if(idxV2 >= revisionV2.Length){
            while(idxV1 < revisionV1.Length){
                int rev1 = int.Parse(revisionV1[idxV1++]);
                if(rev1 > 0){
                    return 1;
                }
            }
            return 0;
        }
        
        return 0;
    }
}