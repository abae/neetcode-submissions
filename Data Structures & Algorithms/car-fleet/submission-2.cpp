class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<std::pair<int, int>> zipped;
        for(int i = 0; i < position.size(); ++i){
            zipped.emplace_back(position[i], speed[i]);
        }
        std::sort(zipped.begin(), zipped.end(), 
            [](auto& a, auto& b){
                return a.first < b.first;
            }
        );

        std::stack<std::pair<int, int>, std::vector<std::pair<int, int>>> carStack(zipped.begin(), zipped.end());

        int fleets = 0;
        double time = 0.f;
        while(!carStack.empty()){
            std::pair<int, int> topCar = carStack.top();
            carStack.pop();
            int dist = target - topCar.first;
            time = ((double)dist) / topCar.second;
            ++fleets;
            // cout << time << " : " << topCar.first << "\n";
            while(!carStack.empty() && (time * carStack.top().second) + carStack.top().first >= target){
                carStack.pop();
            }
        }
        return fleets;
    }
};
