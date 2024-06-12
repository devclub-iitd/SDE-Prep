    int matrixMultiplication(int N, int arr[]) {
        vector<vector<int>> dp(N, vector<int>(N));

        // Initialize the main diagonal to 0
        for (int i = 1; i < N; i++) {
            dp[i][i] = 0;
        }

        // L is the chain length
        for (int len = 2; len < N; len++) {
            for (int i = 1; i < N - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int k = i; k <= j - 1; k++) {
                    int q = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                    dp[i][j] = min(dp[i][j], q);
                }
            }
        }

        return dp[1][N - 1];
    }
};