class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> hist;
        vector<int> out;
        for (int i=0; i<nums.size(); ++i){
            while(!hist.empty() && nums[i] >= nums[hist.back()]){
                hist.pop_back();
            }
            hist.push_back(i);
            if(hist.front() <= i - k){
                hist.pop_front();
            }
            if(i >= k - 1){
                out.push_back(nums[hist.front()]);
            }
        }
        return out;
    }
};