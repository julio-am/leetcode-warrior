class FirstUnique {
private:

queue<int> q_; // holds unique values in order
unordered_map<int, int> count; // index, count

public:
    FirstUnique(vector<int>& nums) {
        for (auto n : nums) add(n);
    }    

    int showFirstUnique() {
        // check that all numbers in our queue are still unique
        while (!q_.empty()) {
            if (count[q_.front()] == 1) return q_.front();
            
            // top value no longer unique
            q_.pop();
        }

        return -1;
    }
    
    void add(int value) {
        // if the value is not yet seen, push to the queue of unique values
        if (count[value] == 0) q_.push(value);

        count[value] += 1;
    }
};

static const auto fast_io = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();
/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
