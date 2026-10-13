class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> out(temperatures.size(), 0);
        std::stack<std::pair<int, int>> hist;
        for (int i=0; i<temperatures.size(); ++i){
            int temp = temperatures[i];
            while (!hist.empty() && temp > hist.top().second){
                out[hist.top().first] = i - hist.top().first;
                hist.pop();
            }
            hist.push({i, temp});
        }
        return out;
    }
};