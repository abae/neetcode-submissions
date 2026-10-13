class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (true){
            int middle = (left + right) / 2;
            if (left == middle && nums[middle] != target){
                if (target < nums[middle]){
                    return left;
                }
                int adjust = target <= nums[right] ? 0 : 1;
                return right + adjust;
            }
            if (nums[middle] > target){
                right = middle;
            }else if (nums[middle] < target){
                left = middle;
            }else{ //nums[middle] == target
                return middle;
            }
        }
    }
};