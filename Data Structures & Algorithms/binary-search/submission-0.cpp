class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (true){
            int test_i = (left + right) / 2;
            if (left == test_i && nums[test_i] != target){
                return -1;
            }
            if (nums[test_i] > target){
                right = test_i;
            }else if (nums[test_i] < target){
                left = test_i;
            }else{ //nums[test_i] == target
                return test_i;
            }
        }
    }
};