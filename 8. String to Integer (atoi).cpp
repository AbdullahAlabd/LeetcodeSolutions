class Solution {
public:
    int myAtoi(string s) {
        long long res = 0;
        int sign = 1;
        bool digitEncountered = false;
        for(char ch : s) {
            if(!digitEncountered) {
                if(ch == ' ') {
                    continue;
                }
                if(ch == '+' || ch == '-') {
                    sign = ch == '-' ? -1 : 1;
                } else if(ch >= '0' && ch <= '9') {
                    res = ch - '0';
                } else {
                    break;
                }
                digitEncountered = true;
            } else {
                if(ch < '0' || ch > '9') {
                    break;
                }
                res = res * 10 + ch - '0';
                if(res * sign > INT_MAX) {
                    return INT_MAX;
                } else if(res * sign < INT_MIN) {
                    return INT_MIN;
                }
            }
        }
        res *= sign;
        return res;
    }
};