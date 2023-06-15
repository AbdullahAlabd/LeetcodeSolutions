vector<int> Solution::repeatedNumber(const vector<int> &arr) {
    vector<int> A(arr);
    for(int i = 0; i < A.size(); i++) {
        while(A[i] != i + 1) {
            if(A[i] == A[A[i] - 1]) {
                break;
            }
            swap(A[i], A[A[i] - 1]);
        }
    }
    for(int i = 0; i < A.size(); i++) {
        if(A[i] != i + 1) {
            return {A[i], i + 1};
        }
    }
    return {};
}