class Solution {
public:
    int maxSatisfaction(vector<int> &a) {
        sort(a.begin(), a.end());
        
        vector<vector<int>> bonus(a.size() + 1, vector<int>(a.size() + 1, -1e9));
        
        for (int items = 0; items <= a.size(); items++) {
            bonus[items][0] = 0;
            for (int taken = 1; taken <= items; taken++)
                bonus[items][taken] = max(bonus[items - 1][taken], bonus[items - 1][taken - 1] + a[items - 1] * taken);
        }
                
        return *max_element(bonus.back().begin(), bonus.back().end());
    }
};