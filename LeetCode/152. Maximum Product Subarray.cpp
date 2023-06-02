class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int globalMax = INT_MIN, curMin = 0, curMax = 0, prevMin = 0, prevMax = 0;
        for(int num: nums) {
            if(num == 0) {
                curMin = curMax = 0;
            }
            prevMin = curMin, prevMax = curMax;
            curMin = (curMin == 0 ? num : min({num, num * prevMax, num * prevMin}));
            curMax = (curMax == 0 ? num : max({num, num * prevMin, num * prevMax}));
            globalMax = max(globalMax, curMax);
        }
        return globalMax;
    }
};