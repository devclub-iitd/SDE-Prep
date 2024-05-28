# Recursive
class Solution:
    def lastRemaining(self, n: int) -> int:
        # Base case: if there's only one number left, return it
        if n == 1:
            return 1
        # The last remaining number in the current sequence can be found by using the last remaining number in a sequence of half the size,
        # then scaling up and adjusting the result appropriately.
        return 2 * (1 + n // 2 - self.lastRemaining(n // 2))


# Iterative
class Solution:
    def lastRemaining(self, n: int) -> int:
        head = 1  # The starting number in the current sequence
        step = 1  # The step size between consecutive numbers in the current sequence
        left = True  # Direction of elimination: True for left-to-right, False for right-to-left

        while n > 1:
            if left or n % 2 == 1:
                # If we're eliminating from the left or the number of elements is odd, the head moves
                head += step
            # Every iteration, the step size doubles
            step *= 2
            # The number of remaining elements is halved
            n //= 2
            # Toggle the direction
            left = not left
        
        return head

