class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;
        for (auto& b : buildings) {
            events.emplace_back(b[0], -b[2]); // Start of a building
            events.emplace_back(b[1], b[2]);  // End of a building
        }
        sort(events.begin(), events.end());
        
        multiset<int> heights = {0};
        vector<vector<int>> result;
        int prevHeight = 0;
        
        for (auto& [x, h] : events) {
            if (h < 0) {
                heights.insert(-h);
            } else {
                heights.erase(heights.find(h));
            }
            
            int maxHeight = *heights.rbegin();
            if (maxHeight != prevHeight) {
                result.push_back({x, maxHeight});
                prevHeight = maxHeight;
            }
        }
        
        return result;
    }
};
