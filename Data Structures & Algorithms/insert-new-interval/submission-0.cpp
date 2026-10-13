class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        bool intervalPlaced = false;
        auto it = intervals.begin();
        while(it != intervals.end()){
            auto interval = *it;
            if(interval[1] < newInterval[0]){
                result.push_back(interval);
                ++it;
            }else if(interval[0] > newInterval[1]){
                result.push_back(newInterval);
                intervalPlaced = true;
                break;
            }else{
                result.push_back({std::min(interval[0], newInterval[0]), std::max(interval[1], newInterval[1])});
                ++it;
                intervalPlaced = true;
                break;
            }
        }
        while(it != intervals.end()){
            auto interval = *it;
            if(result.back()[1] >= interval[0]){
                result.back()[1] = std::max(result.back()[1], interval[1]);
                ++it;
            }else{
                result.push_back(interval);
                ++it;
            }
        }
        if(!intervalPlaced){
            result.push_back(newInterval);
        }
        return result;
    
    }
};