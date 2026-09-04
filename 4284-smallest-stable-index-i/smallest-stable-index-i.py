class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        n = len(nums)
        maximum = nums.copy()
        minimum = nums.copy()
        

        for i in range(1,n):
            maximum[i] = max(maximum[i-1],nums[i])
        
        for i in range(n-2,-1,-1):
            minimum[i] = min(nums[i],minimum[i+1])
        
        for i in range(n):
            max_left = maximum[i]
            min_right = minimum[i]
            score = max_left - min_right
            if score <= k:
                return i

        return -1