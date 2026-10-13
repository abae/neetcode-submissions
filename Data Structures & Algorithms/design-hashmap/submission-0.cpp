class MyHashMap {
private:
    static constexpr int NUM_BUCKETS = 100;
    std::vector<std::vector<std::pair<int, int>>> buckets_;
public:
    MyHashMap() : buckets_(NUM_BUCKETS) {
        
    }
    
    void put(int key, int value) {
        int hashKey = key % NUM_BUCKETS;
        std::vector<std::pair<int, int>>& bucket = buckets_[hashKey];
        auto it = std::find_if(bucket.begin(), bucket.end(),
            [key](const auto& p){
                return p.first == key;
            }
        );
        if (it == bucket.end()){
            buckets_[hashKey].push_back(std::pair<int, int>(key, value));
        }else{
            it->second = value;
        }
    }
    
    int get(int key) {
        int hashKey = key % NUM_BUCKETS;
        if (buckets_[hashKey].empty()){
            return -1;
        }
        std::vector<std::pair<int, int>>& bucket = buckets_[hashKey];
        auto it = std::find_if(bucket.begin(), bucket.end(),
            [key](const auto& p){
                return p.first == key;
            }
        );
        if (it == bucket.end()){
            return -1;
        }
        return it->second;
    }
    
    void remove(int key) {
        int hashKey = key % NUM_BUCKETS;
        if (buckets_[hashKey].empty()){
            return;
        }
        std::vector<std::pair<int, int>>& bucket = buckets_[hashKey];
        auto it = std::find_if(bucket.begin(), bucket.end(),
            [key](const auto& p){
                return p.first == key;
            }
        );
        if (it != bucket.end()){
            bucket.erase(it);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */