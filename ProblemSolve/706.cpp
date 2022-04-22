/******************
 * Design HashMap *
 ******************/

class MyHashMap {
public:
    int hashMap[1000001]{};
    
    MyHashMap() {
    }
    
    void put(int key, int value) {
        if(value == 0){
            hashMap[key] = -1000001;
            return;
        }
        
        hashMap[key] = -value;
    }
    
    int get(int key) {
        if(hashMap[key] >= 0){
            return -1;
        }
        
        int val = hashMap[key];
        
        return (val == -1000001) ? 0 : -val;
    }
    
    void remove(int key) {
        hashMap[key] = 1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */