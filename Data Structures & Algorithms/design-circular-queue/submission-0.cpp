class MyCircularQueue {
private:
    std::vector<int> queue_;
    int start_ = 0;
    int size_ = 0;
    int capacity_;
public:
    MyCircularQueue(int k) : capacity_(k){
        queue_.resize(k);
    }
    
    bool enQueue(int value) {
        if (this->isFull()){
            return false;
        }
        ++size_;
        queue_[start_] = value;
        --start_;
        start_ = (start_ + capacity_) % capacity_;
        return true;
    }
    
    bool deQueue() {
        if (this->isEmpty()){
            return false;
        }
        --size_;
        return true;
    }
    
    int Front() {
        if (this->isEmpty()){
            return -1;
        }
        return queue_[(start_ + size_) % capacity_];
    }
    
    int Rear() {
        if (this->isEmpty()){
            return -1;
        }
        return queue_[(start_ + 1) % capacity_];
    }
    
    bool isEmpty() {
        return size_ == 0;
    }
    
    bool isFull() {
        return size_ == capacity_;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */