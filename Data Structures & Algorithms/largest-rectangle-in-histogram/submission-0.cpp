class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<int> hist;
        int maxArea = 0;
        heights.push_back(0);
        for (int i=0; i<heights.size(); ++i){
            while(!hist.empty() && heights[i] < heights[hist.top()]){
                int h = heights[hist.top()];
                hist.pop();
                int w = (hist.empty() ? i : i - hist.top() - 1);
                maxArea = std::max(maxArea, h*w);
            }
            hist.push(i);
        }
        return maxArea;
    }
};