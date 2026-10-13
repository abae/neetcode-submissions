class TimeMap {
private:
    std::unordered_map<std::string, std::map<int, std::string>> buffer_;

public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        buffer_[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (buffer_[key].empty()){
            return "";
        }
        auto it = buffer_[key].upper_bound(timestamp);
        if (it == buffer_[key].begin()){
            return "";
        }
        --it;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */