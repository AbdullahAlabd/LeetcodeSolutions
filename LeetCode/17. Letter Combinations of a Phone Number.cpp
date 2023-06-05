class Solution {
    void generateCombinations(int idx, string& combination, vector<string> &allCombinations,
    const string& digits, const vector<string> &press) {
        if(idx == digits.length()) {
            if(!combination.empty()) {
                allCombinations.push_back(combination);
            }
            return;
        }
        for(char ch : press[digits[idx] - '2']) {
            combination.push_back(ch);
            generateCombinations(idx + 1, combination, allCombinations, digits, press);
            combination.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> press{"abc", "def", "ghi", "jkl", "mno", "pqrs","tuv", "wxyz"};
        string combination = "";
        vector<string> allCombinations;
        generateCombinations(0, combination, allCombinations, digits, press);
        return allCombinations;
    }
};