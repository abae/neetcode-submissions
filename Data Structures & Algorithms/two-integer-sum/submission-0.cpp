class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;

        for (int i=0; i<nums.size(); ++i){
            int compliment = target - nums[i];
            auto it = seen.find(nums[i]);
            if (it != seen.end()){
                return {it->second, i};
            }else{
                seen.insert({compliment, i});
            }
        }
        return {0,0};
    }
};