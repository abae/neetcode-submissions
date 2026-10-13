class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest = prices[0];
        int maxOut = 0;
        for (int price : prices){
            if (price < lowest){
                lowest = price;
            }else if (price - lowest > maxOut){
                maxOut = price - lowest;
            }
        }
        return maxOut;
    }
};