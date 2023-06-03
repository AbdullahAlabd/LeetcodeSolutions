class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {       
        int res = 0;
        vector<int> dp(nums.size(), 0);
        for(int idx = 0; idx < nums.size(); idx++) {
            dp[idx] = 1;
            for(int left = 0; left < idx; left++) {
                if(nums[left] < nums[idx]) {
                    dp[idx] = max(dp[idx], 1 + dp[left]);
                }
            }
            res = max(res, dp[idx]);
        }
        return res;
    }
};