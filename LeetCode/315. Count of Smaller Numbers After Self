class Solution {
    static const int BASE = 1e4 + 1;
    struct BIT{
        static const int MAXN = 2 * BASE;
        int data[MAXN] = {};
        int get(int idx) {
            int res = 0;
            while(idx) {
                res += data[idx];
                idx -= idx & -idx;
            }
            return res;
        }
        void update(int idx, int val) {
            while(idx < MAXN) {
                data[idx] += val;
                idx += idx & -idx;
            }
        }
    };
public:
    vector<int> countSmaller(vector<int>& nums) {
        BIT bit;
        vector<int> ans(nums.size(), 0);
        for(int idx = nums.size() - 1; idx >= 0; idx--) {
            ans[idx] = bit.get(nums[idx] + BASE - 1);
            bit.update(nums[idx] + BASE, 1);
        }
        return ans;
    }
};