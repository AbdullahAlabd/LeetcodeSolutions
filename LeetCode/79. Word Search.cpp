class Solution {
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool bt(int idx, int row, int col, vector<vector<bool>> &visited,
    const string word, const vector<vector<char>>& board) {
        if(board[row][col] != word[idx]) {
            return false;
        }
        if(idx == word.length() - 1) {
            return true;
        }
        bool ans = false;
        visited[row][col] = true;
        for(auto &[dr, dc] : dir) {
            int r = row + dr, c = col + dc;
            if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || visited[r][c]) {
                continue;
            }
            if(bt(idx + 1, r, c, visited, word, board)) {
                ans = true;
                break;
            }
        }
        visited[row][col] = false;
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool> (board[0].size(), false));
        int stFreq = 0, endFreq = 0;
        
        for(int row = 0; row < board.size(); row++) {
            for(int col = 0; col < board[0].size(); col++) {
                if(board[row][col] == word.front()) {
                    stFreq++;
                }
                if(board[row][col] == word.back()) {
                    endFreq++;
                }
            }
        }
        if(stFreq > endFreq) { // optimization
            reverse(word.begin(), word.end());
        }
        for(int row = 0; row < board.size(); row++) {
            for(int col = 0; col < board[0].size(); col++) {
                if(bt(0, row, col, visited, word, board)) {
                    return true;
                }
            }
        }
        return false;
    }
};
