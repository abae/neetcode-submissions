class KthLargest {
private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> highestScores_;
    int k_;
public:
    KthLargest(int k, vector<int>& nums) : k_(k){
        for(int num : nums){
            if(highestScores_.size() < k){
                highestScores_.push(num);
                continue;
            }
            if(num > highestScores_.top()){
                highestScores_.pop();
                highestScores_.push(num);
            }
        }
    }
    
    int add(int val) {
        if(highestScores_.size() < k_){
            highestScores_.push(val);
        } else if(val > highestScores_.top()){
            highestScores_.pop();
            highestScores_.push(val);
        }
        return highestScores_.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */