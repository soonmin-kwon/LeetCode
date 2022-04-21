/******************
 * Design HashSet *
 ******************/

public class MyHashSet {
    bool[] hash = new bool[1000001];
    
    public MyHashSet() {
        
    }
    
    public void Add(int key) {
        hash[key] = true;
    }
    
    public void Remove(int key) {
        hash[key] = false;
    }
    
    public bool Contains(int key) {
        return hash[key];
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.Add(key);
 * obj.Remove(key);
 * bool param_3 = obj.Contains(key);
 */