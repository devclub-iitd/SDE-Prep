// DP Solution
class Solution {
public:
    int n;
    vector<vector<int>> dp;
    vector<int> a;
    void dpf(int i, int j) {
        if(i>j)return;
        if(dp[i][j]!=0)return;
        dpf(i+2,j);
        dpf(i,j-2);
        dpf(i+1,j-1);
        int temp = 0;
        temp = max(temp , a[i] + dp[i+2][j]);
        temp = max(temp , a[j] + dp[i][j-2]);
        temp = max(temp , max(a[i],a[j]) + dp[i+1][j-1]);
        dp[i][j] = temp;
    }
    bool stoneGame(vector<int>& piles) {
        n = piles.size();
        a = piles;
        dp = vector<vector<int>>(n, vector<int>(n, 0));
        for(int i = 0 ; i < n - 1 ; i ++){
            dp[i][i+1] = max(a[i],a[i+1]);
        }
        dpf(0,n-1);
        return 2*dp[0][n-1] > accumulate(a.begin(),a.end(),0);
        return true;
    }
};


// O(1) Solution
// Observe that Alice can always either choose all the odd index stones or all the even index stones.
// So if sum(odd)>sum(even) then s/he chooses the odd indices, otherwise the opposite.

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};

