class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int iLeft = 0;
        int iRight = numbers.size()-1;
        while(iLeft < iRight){
            int sum = numbers[iLeft] + numbers[iRight];
            if(sum == target){
                return {iLeft+1, iRight+1};
            }else if(sum < target){
                ++iLeft;
            }else if(sum > target){
                --iRight;
            }
        }
        return {};
    }
};