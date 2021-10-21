/********************************
 * Insert Delete GetRandom O(1) *
 ********************************/

class RandomizedSet {
public:
    vector<int> elements;               //insert한 값들 저장
    unordered_map<int,int> hash;        //insert한 값들을 key로 가지고 elements배열에서의 key값의 index를 value로 갖는 hash table
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        //이미 있으면 false
        if(hash.find(val) != hash.end()){
            return false;
        }
        else{
            //없으면 elements에 넣어주고, hash에 val이 index값을 가지도록 해준다.
            elements.push_back(val);
            hash[val] = elements.size() - 1;            
            return true;
        }
    }
    
    bool remove(int val) {
        //이미 있으면 remove할 수 있다
        if(hash.find(val) != hash.end()){
            //벡터에서 마지막 원소를 제거하는 건 O(1)의 시간 복잡도를 가지기 때문에
            //맨 마지막 원소를 제거할 원소의 위치로 바꾸고 맨 마지막 원소를 지워준다.
            int lastElement = elements.back();
            elements[hash[val]] = lastElement;
            elements.pop_back();
            
            hash[lastElement] = hash[val];
            hash.erase(val);
            
            return true;
        }
        else{
            return false;
        }
    }
    
    int getRandom() {
        int idx = rand() % elements.size();
        return elements[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */