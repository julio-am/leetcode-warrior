class LRUCache {
private:

    list<pair<int,int>> cache_;
    unordered_map<int, list<pair<int,int>>::iterator> mp_;
    int capacity_;

public:
    LRUCache(int capacity) : capacity_(capacity){
    }
    
    int get(int key) {
        if (!mp_.contains(key)) return -1;
        
        auto it = mp_[key];
        cache_.splice(cache_.begin(), cache_, it);
        return it->second;
    }
    
    void put(int key, int value) {
        if (mp_.contains(key)) {
            // update value
            auto it = mp_[key];
            it->second = value;

            // move recently used to front
            cache_.splice(cache_.begin(), cache_, it);
            return;
        }

        cache_.push_front({key, value});
        mp_[key] = cache_.begin();

        if (cache_.size() > capacity_) {
            // erase least recently used key
            mp_.erase(cache_.back().first);
            cache_.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
