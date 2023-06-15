class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        const int N = s.length(), K = p.length();
        if(N < K) {
            return {};
        }
        vector<int> wFreq(26, 0), pFreq(26, 0);
        for(int i = 0; i < K; i++) {
            pFreq[p[i] - 'a']++;
            if(i < K - 1) {
                wFreq[s[i] - 'a']++;    
            }
        }
        vector<int> result;
        for(int i = K - 1; i < N; i++) {
            wFreq[s[i] - 'a']++;
            if(wFreq == pFreq) { // vector equality check compares each element
                result.push_back(i - K + 1);
            }
            wFreq[s[i - K + 1] - 'a']--;
        }
        return result;
    }
};