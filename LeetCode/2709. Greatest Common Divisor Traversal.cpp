class Solution {
    static const int MAXN = 1e5 + 5; 
    
    struct DSU {
        int parent[MAXN], rank[MAXN];
        DSU() {
            for(int idx = 0; idx < MAXN; idx++) {
                parent[idx] = idx, rank[idx] = 1;
            }
        }
        int root(int idx) {
            while(idx != parent[idx]) {
                idx = parent[idx] = parent[parent[idx]];
            }
            return idx;
        }
        void unite(int a, int b) {
            a = root(a), b = root(b);
            if(a == b) return;
            if(rank[a] < rank[b]) {
                swap(a, b);
            }
            if(rank[a] == rank[b]) { 
                rank[a]++;
            }
            parent[b] = a;
        }
    };

    vector<int> getSmallestPrimeFactors() { 
        vector<int> SPF(MAXN, 1); // smallest prime factor
        for(int i = 1; i < MAXN; i++) {
            SPF[i] = (i & 1) ? i : 2;
        }
        for(int p = 3; p * p < MAXN; p += 2) {
            if(SPF[p] == p) { // prime
                for(int i = p * p; i < MAXN; i += 2 * p) {
                    if(SPF[i] == i) { // not marked yet
                        SPF[i] = p;
                    }
                }
            }
        }
        return SPF;
    }

public:
    bool canTraverseAllPairs(vector<int>& nums) {
        DSU dsu;
        vector<int> SPF = getSmallestPrimeFactors();
        for(int num : nums) {
            int cur = num, lastDev = 1;
            while(cur > 1) { // factorization in O Log(num)
                if(SPF[cur] != lastDev) {
                    dsu.unite(num, SPF[cur]);
                    lastDev = SPF[cur];
                }
                cur /= SPF[cur];
            }
        }
        if(nums[0] == 1) { // corner case
            return nums.size() == 1;
        }
        for(int num : nums) {
            if(dsu.root(num) != dsu.root(nums[0])) {
                return false;
            }
        }
        return true;
    }
};