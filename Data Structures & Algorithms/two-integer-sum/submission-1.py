class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = {}
        for i in range(len(nums)):
            if(nums[i] in seen):
                return [seen[nums[i]], i]
            compliment = target - nums[i]
            seen[compliment] = i