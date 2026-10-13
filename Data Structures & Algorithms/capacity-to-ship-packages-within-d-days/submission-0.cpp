class Solution {
private:
    bool canShipShip(vector<int>& weights, int days, int capacity){
        int t = 1;
        int space = capacity;
        for(int weight:weights){
            if(space >= weight){
                space -= weight;
            }else{
                space = capacity - weight;
                ++t;
            }
        }
        return t <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int minShipCapacity = *std::max_element(weights.begin(), weights.end());
        int maxShipCapacity = std::accumulate(weights.begin(), weights.end(), 0);
        while(minShipCapacity < maxShipCapacity){
            int testShipCapacity = minShipCapacity + (maxShipCapacity - minShipCapacity) / 2;
            if(canShipShip(weights, days, testShipCapacity)){
                maxShipCapacity = testShipCapacity;
            }else{
                minShipCapacity = testShipCapacity + 1;
            }
        }
        return minShipCapacity;
    }
};