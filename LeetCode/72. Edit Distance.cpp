class Solution {
public:
    int minDistance(string A, string B) {
        if(A.length() < B.length()) {
            // to have O(min(sz(A), sz(B))) space complixity
            swap(A, B);
        }
        vector<vector<int>> dp(2, vector<int>(B.length() + 1, 0));
        for(int i = 0; i <= B.length(); i++) {
            dp[0][i] = i;
        }
        bool last = 0, now;
        for(int idxA = 1; idxA <= A.length(); idxA++) {
            now = last ^ 1;
            dp[now][0] = idxA;
            for(int idxB = 1; idxB <= B.length(); idxB++) {
                dp[now][idxB] = INT_MAX;
                if (A[idxA - 1] == B[idxB - 1]) {
                    dp[now][idxB] = dp[last][idxB - 1];
                }
                dp[now][idxB] = min({dp[now][idxB],
                1 + dp[last][idxB - 1], // replace in A
                1 + dp[last][idxB], // delete from A
                1 + dp[now][idxB - 1]}); // insert into A
            }
            last = now;
        }
        return dp[now][B.size()];
    }
};
