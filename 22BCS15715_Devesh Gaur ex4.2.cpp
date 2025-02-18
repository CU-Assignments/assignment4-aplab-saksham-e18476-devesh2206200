#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> beautifulArray(int n) {
    vector<int> res(n);
    for (int i = 0; i < n; i++)
        res[i] = i + 1;
    return res;
}

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int, int>> events;
    for (const auto& b : buildings) {
        events.push_back({b[0], -b[2]}); 
        events.push_back({b[1], b[2]});  
    }
    sort(events.begin(), events.end());
    
    multiset<int> heights = {0};
    vector<vector<int>> result;
    int prevHeight = 0;
    
    for (const auto& e : events) {
        if (e.second < 0) {
            heights.insert(-e.second);
        } else {
            heights.erase(heights.find(e.second));
        }
        int currentHeight = *heights.rbegin();
        if (currentHeight != prevHeight) {
            result.push_back({e.first, currentHeight});
            prevHeight = currentHeight;
        }
    }
    return result;
}

int main() {
    int n = 5;
    vector<int> result = beautifulArray(n);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    vector<vector<int>> buildings = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    vector<vector<int>> skyline = getSkyline(buildings);
    for (const auto& point : skyline) {
        cout << "[" << point[0] << "," << point[1] << "] ";
    }
    cout << endl;
    return 0;
}
