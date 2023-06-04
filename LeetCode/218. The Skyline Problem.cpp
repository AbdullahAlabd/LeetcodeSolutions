class Solution {

public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        set<int> points;
        unordered_map<int, vector<int>> endHeights;
        unordered_map<int, vector<int>> startHeights;
        for(auto& building : buildings) {
            int left = building[0], right = building[1], height = building[2];
            points.insert(left);
            points.insert(right);
            endHeights[right].push_back(height);
            startHeights[left].push_back(height);
        }

        multiset<int> heights;
        int lastHeight = 0, maxHeight;
        vector<vector<int>> answer;
        for(auto& point : points) {
            for(int& height : endHeights[point]) {
                auto it = heights.find(height);
                if(it != heights.end()) {
                    heights.erase(it);
                }
            }
            for(int& height : startHeights[point]) {
                heights.insert(height);
            }
            maxHeight = heights.empty() ? 0 : *heights.rbegin();
            if(maxHeight != lastHeight) {
                answer.push_back({point, maxHeight});
                lastHeight = maxHeight;
            }
        }
        return answer;
    }
};