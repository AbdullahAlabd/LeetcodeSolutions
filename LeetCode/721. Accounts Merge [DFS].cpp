class Solution {
    void DFS(string node, vector<string> &component, unordered_set<string>& visited,
    unordered_map<string, unordered_set<string>>& adj) {
        visited.insert(node);
        component.push_back(node);
        for(auto u : adj[node]) {
            if(!visited.count(u)) {
                DFS(u, component, visited, adj);
            }
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, unordered_set<string>> adj;
        unordered_set<string> visited;
        unordered_map<string, string> emailOwner;
        for(auto & account : accounts) {
            for(int i = 1; i < account.size(); i++) {
                adj[account[i]].insert(account[1]);
                adj[account[1]].insert(account[i]);
                emailOwner[account[i]] = account[0];
            }
        }
        vector<vector<string>> answer;
        for(auto& [email, _] : adj) {
            vector<string> component;
            if(!visited.count(email)) {
                component.push_back(emailOwner[email]);
                DFS(email, component, visited, adj);
            }
            if(component.size()) {
                sort(component.begin() + 1, component.end());
                answer.push_back(component);
            }
        }
        return answer;
    }
};