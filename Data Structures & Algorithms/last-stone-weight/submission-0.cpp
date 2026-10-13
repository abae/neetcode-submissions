class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> stonesQueue(stones.cbegin(), stones.cend());
        while(stonesQueue.size() > 1){
            int stone1 = stonesQueue.top();
            stonesQueue.pop();
            int stone2 = stonesQueue.top();
            stonesQueue.pop();
            int newStone = stone1 - stone2;
            if(newStone > 0){
                stonesQueue.push(newStone);
            }
        }
        if(stonesQueue.size() == 0){
            return 0;
        }
        return stonesQueue.top();
    }
};