# DP Solution
class Solution:
    def __init__(self):
        self.n = 0
        self.dp = []
        self.a = []

    def dpf(self, i: int, j: int) -> None:
        if i > j:
            return
        if self.dp[i][j] != 0:
            return
        self.dpf(i + 2, j)
        self.dpf(i, j - 2)
        self.dpf(i + 1, j - 1)
        temp = 0
        temp = max(temp, self.a[i] + (self.dp[i + 2][j] if i + 2 <= j else 0))
        temp = max(temp, self.a[j] + (self.dp[i][j - 2] if i <= j - 2 else 0))
        temp = max(temp, max(self.a[i], self.a[j]) + (self.dp[i + 1][j - 1] if i + 1 <= j - 1 else 0))
        self.dp[i][j] = temp

    def stoneGame(self, piles: List[int]) -> bool:
        self.n = len(piles)
        self.a = piles
        self.dp = [[0] * self.n for _ in range(self.n)]
        
        for i in range(self.n - 1):
            self.dp[i][i + 1] = max(self.a[i], self.a[i + 1])
        
        self.dpf(0, self.n - 1)
        return 2 * self.dp[0][self.n - 1] > sum(self.a)


# O(1) Solution
# Observe that Alice can always either choose all the odd index stones or all the even index stones.
# So if sum(odd)>sum(even) then s/he chooses the odd indices, otherwise the opposite.

class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        return True  #

