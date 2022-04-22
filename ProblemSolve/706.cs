/******************
 * Design HashMap *
 ******************/

public class MyHashMap {
    private int[] hashMap = new int[1000001];
    public MyHashMap() {
    }
    
    public void Put(int key, int val) {
        if(val == 0){
            hashMap[key] = -1000001;
            return;
        }
        
        hashMap[key] = -val;
    }
    
    public int Get(int key) {
        if(hashMap[key] >= 0){
            return -1;
        }
        
        int val = hashMap[key];
        
        if(val == -1000001){
            return 0;
        }
            
        return -val;
    }
    
    public void Remove(int key) {
        hashMap[key] = 1;
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.Put(key,value);
 * int param_2 = obj.Get(key);
 * obj.Remove(key);
 */