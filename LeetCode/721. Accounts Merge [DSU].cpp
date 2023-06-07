class Solution {
    static const int MAXN = 1e4 + 4;
    struct DSU {
        int parent[MAXN], rank[MAXN];
        DSU() {
            for(int i = 0; i < MAXN; i++) {
                parent[i] = i, rank[i] = 1;
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
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DSU dsu;
        unordered_map<string, int> mailIds;
        vector<string> mailIdOwner(MAXN);
        int count = 0;
        for(int i = 0; i < accounts.size(); i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                int& mId = mailIds[accounts[i][j]];
                if(mId == 0) {
                    mId = ++count;
                }
                dsu.unite(mailIds[accounts[i][1]], mId);
                mailIdOwner[mId] = accounts[i][0];
            }
        }
        vector<vector<string>> answer;
        unordered_map<int, vector<string>> distinctAccounts;
        for(auto &[mail, mailId] : mailIds) {
            auto &account = distinctAccounts[dsu.root(mailId)];
            if(account.empty()) {
                account.push_back(mailIdOwner[mailId]);
            }
            account.push_back(mail);
        }
        for(auto &[_, account] : distinctAccounts) {
            sort(account.begin() + 1, account.end());
            answer.push_back(account);
        }
        return answer;

    }
};