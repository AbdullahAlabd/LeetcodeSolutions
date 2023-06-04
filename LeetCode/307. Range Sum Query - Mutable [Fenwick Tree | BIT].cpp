class NumArray {
    struct BIT {
        static const int MAXN = 3e4 + 4;
        int data[MAXN] = {}; // 1-based;
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
    BIT bit;
    NumArray(vector<int>& nums) {
        for(int index = 0; index < nums.size(); index++) {
            bit.update(index + 1, nums[index]);
        }
    }
    void update(int index, int val) {
        int valAtIdx = bit.get(index + 1) - bit.get(index);
        bit.update(index + 1, val - valAtIdx);
    }
    
    int sumRange(int left, int right) {
        return bit.get(right + 1) - bit.get(left);
    }
};