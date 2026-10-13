class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(),
            [](auto& a, auto& b){
                return a[0] < b[0];
            }
        );
        vector<vector<int>> result;
        for(auto& interval : intervals){
            if(result.empty() || result.back()[1] < interval[0]){
                result.push_back(interval);
            }else{ //result.back()[1] >= interval[0]
                result.back()[1] = std::max(result.back()[1], interval[1]);
            }
        }
        return result;
    }
};