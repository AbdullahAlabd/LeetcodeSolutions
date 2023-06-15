vector<int> Solution::repeatedNumber(const vector<int> &arr) {
    long long s1 = 0, s2 = 0;
    int A, B;
    for(int i = 0; i < arr.size(); i++) {
        s1 += arr[i] - (i + 1);
        s2 += 1LL * arr[i] * arr[i] - (i + 1LL) * (i + 1);
    }
    A = (s2  + s1 * s1) / (2 * s1);
    B = A - s1;
    return {A, B};
}