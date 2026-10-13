#include <limits>

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), 
            [](auto& a, auto& b){
                return a[1] < b[1];
            }
        );
        int lastEnd = INT_MIN;
        int result = 0;
        for(const auto& interval : intervals){
            if(interval[0] >= lastEnd){
                lastEnd = interval[1];
            }else{
                result++;
            }
        }
        return result;
    }
};