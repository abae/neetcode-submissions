class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        if (nums.empty()){
            return {};
        }
        int n = nums.size();
        std::unordered_set<int> seen;
        for(int num : nums){
            seen.insert(num);
        }
        std::vector<int> out;
        for(int i = 1; i <= n; ++i){
            if(!seen.count(i)){
                out.push_back(i);
            }
        }
        return out;
    }
};