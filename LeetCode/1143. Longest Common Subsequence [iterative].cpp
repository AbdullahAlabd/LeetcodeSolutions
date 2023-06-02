class Solution {
public:
    int longestCommonSubsequence(string A, string B) {
        vector<vector<int>> LCS(2, vector<int>(B.length() + 1, 0));
        bool last = 0, now;
        for(int idxA = 1; idxA <= A.length(); idxA++) {
            now = last ^ 1;
            for(int idxB = 1; idxB <= B.length(); idxB++) {
                if(A[idxA - 1] == B[idxB - 1]) {
                    LCS[now][idxB] = 1 + LCS[last][idxB - 1];
                } else {
                    LCS[now][idxB] = max(LCS[now][idxB - 1], LCS[last][idxB]);
                }
            }
            last = now;
        }
        return LCS[now][B.length()];
    }
};