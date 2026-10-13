class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> closestPts;
        std::vector<std::vector<int>> result;
        for(int i=0; i<points.size(); ++i){
            std::vector<int>& point = points[i];
            int sqDist = point[0] * point[0] + point[1] * point[1];
            closestPts.push({sqDist, i});
        }
        for(int i=0; i<k; ++i){
            int nextClosest = closestPts.top().second;
            closestPts.pop();
            result.push_back(points[nextClosest]);
        }
        return result;
    }
};