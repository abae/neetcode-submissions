class Solution {
public:
    bool canEatAllBananas(vector<int>& piles, int h, int speed){
        int t = 0;
        for(int bananas:piles){
            t += bananas/speed + (bananas % speed != 0);
        }
        return t <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxEatSpeed = *std::max_element(piles.begin(), piles.end());
        int minEatSpeed = 1;
        while(minEatSpeed < maxEatSpeed){
            int testSpeed = minEatSpeed + (maxEatSpeed - minEatSpeed) / 2;
            if(canEatAllBananas(piles, h, testSpeed)){
                maxEatSpeed = testSpeed;
            }else{
                minEatSpeed = testSpeed + 1;
            }
        }
        return minEatSpeed;
    }
};