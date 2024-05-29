class Solution:
    def findPeakElement(self, nums: list[int]) -> int:
        left, right = 0, len(nums) - 1

        while left < right:
            mid = (left + right) // 2

            if nums[mid - 1] <= nums[mid] >= nums[mid + 1]:
                return mid
            elif nums[mid] < nums[mid + 1]:
                left = mid + 1
            else:
                right = mid

        return left