class Solution {
    int LCS(int idxA, int idxB, vector<vector<int>>& memo, const string& A, const string& B) {
        if(idxA >= A.length() || idxB >= B.length()) {
            return 0;
        }
        int &ans = memo[idxA][idxB];
        if(ans != -1) {
            return ans;
        }
        if(A[idxA] == B[idxB]) {
            ans = 1 + LCS(idxA + 1, idxB + 1, memo, A, B);
        } else {
            ans = max(LCS(idxA + 1, idxB, memo, A, B), LCS(idxA, idxB + 1, memo, A, B));
        }
        return ans;
    }
public:
    int longestCommonSubsequence(string A, string B) {
        vector<vector<int>> memo(A.length(), vector<int>(B.length(), -1));
        return max(LCS(0, 0, memo, A, B), 0);
        
    }
};