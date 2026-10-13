class LRUCache {
private:
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache;
    std::list<std::pair<int, int>> hist;
    int capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!cache.contains(key)){
            return -1;
        }
        int value = cache[key]->second;
        hist.splice(hist.begin(), hist, cache[key]);
        return value;
    }
    
    void put(int key, int value) {
        if (cache.contains(key)){
            hist.splice(hist.begin(), hist, cache[key]);
            cache[key]->second = value;
        }else if (hist.size() >= capacity){
            int oldKey = hist.back().first;
            hist.pop_back();
            cache.erase(oldKey);
            hist.push_front({key, value});
            cache[key] = hist.begin();
        }else{
            hist.push_front({key, value});
            cache[key] = hist.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */