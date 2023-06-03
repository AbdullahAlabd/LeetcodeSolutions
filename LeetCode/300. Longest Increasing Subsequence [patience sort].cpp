class Solution {
public:
    int lengthOfLIS(vector<int>& nums) { // O(N Log N)
        vector<int> piles;
        for(int num : nums) { // parience sort with virtual piles
            auto pilePtr = lower_bound(piles.begin(), piles.end(), num);
            if(pilePtr == piles.end()) {
                piles.push_back(num);
            } else {
                *pilePtr = num;
            }
        }
        return piles.size();
    }
};