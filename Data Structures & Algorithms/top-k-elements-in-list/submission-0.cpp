class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> counts;
        for (int num : nums){
            counts[num]++;
        }
        vector<pair<int, int>> sorted(counts.begin(), counts.end());
        sort(sorted.begin(), sorted.end(),
            [](const auto& a, const auto& b){
                return a.second > b.second;
            }
        );
        vector<int> out;
        for (size_t i=0; i<k; i++){
            out.push_back(sorted[i].first);
        }
        return out;
    }
};