class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = 0
        curSum = 0
        n = len(nums)
        AllNeg = True

        for i in range(n):
            if nums[i] > 0:
                AllNeg = False
        
        if AllNeg:
            return max(nums)



      
        for i in range(n):
            curSum += nums[i]
            ans = max(ans, curSum)
            if curSum < 0:
                curSum = 0
        
        return ans
