int knapSack(int W, int wt[], int val[], int N) 
{
    vector<vector<int>> dp(2, vector<int>(W + 1, 0));
    bool last = 1, now;
    for(int idx = 0; idx < N; idx++) {
        now = last ^ 1;
        for(int weight = 0; weight <= W; weight++) {
            if(weight >= wt[idx]) {
                dp[now][weight] = val[idx] + dp[last][weight - wt[idx]];
            }
            dp[now][weight] = max(dp[now][weight], dp[last][weight]);        
        }
        last = now;
    }
    return dp[now][W];
}