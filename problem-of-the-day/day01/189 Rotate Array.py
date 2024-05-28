class Solution:
    def reverse(self, i: int, j: int, nums: List[int]) -> None:
        while i < j:
            nums[i], nums[j] = nums[j], nums[i]  # Correctly swap elements
            i += 1
            j -= 1
    
    def rotate(self, nums: List[int], k: int) -> None:
        n = len(nums)  # Define the length of the list
        k = k % n  # Ensure k is within the bounds of the list length
        
        # Call the reverse function as a method of the class
        self.reverse(0, n-1, nums)
        self.reverse(0, k-1, nums)
        self.reverse(k, n-1, nums)