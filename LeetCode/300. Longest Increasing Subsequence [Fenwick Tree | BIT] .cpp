class Solution {
    static const int BASE = 1e4 + 1;
    struct BIT {
        static const int MAXN = 2 * BASE;
        int data[MAXN] = {};
        int get(int idx) {
            int res = 0;
            while(idx) {
                res = max(res, data[idx]);
                idx -= idx & -idx;
            }
            return res;
        }
        void update(int idx, int val) {
            while(idx < MAXN) {
                data[idx] = max(data[idx], val);
                idx += idx & -idx;
            }
        }
    };
public:
    int lengthOfLIS(vector<int>& nums) { // O (N Log N)
        int res = 0;
        vector<int> dp(nums.size(), 0);
        BIT bit;
        for(int idx = 0; idx < nums.size(); idx++) { // an optimization over the DP version
            dp[idx] = 1 + bit.get(nums[idx] + BASE - 1); // find max dp[i] such that nums[i] < nums[idx]
            bit.update(nums[idx] + BASE, dp[idx]);
            res = max(res, dp[idx]);
        }
        return res;
    }
};