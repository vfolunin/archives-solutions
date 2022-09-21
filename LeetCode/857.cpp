class Solution {
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k) {
        vector<pair<double, double>> pairs(quality.size());
        for (int i = 0; i < pairs.size(); i++)
            pairs[i] = { quality[i], wage[i] };
        
        sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
            return a.first / a.second > b.first / b.second;
        });
        
        multiset<int> window;
        int windowSum = 0;
        
        for (int i = 0; i < k; i++) {
            window.insert(pairs[i].first);
            windowSum += pairs[i].first;
        }
        
        double res = pairs[k - 1].second * windowSum * 1.0 / pairs[k - 1].first;
        
        for (int i = k; i < pairs.size(); i++) {
            windowSum -= *prev(window.end());
            window.erase(prev(window.end()));
            
            window.insert(pairs[i].first);
            windowSum += pairs[i].first;
            
            res = min(res, pairs[i].second * windowSum * 1.0 / pairs[i].first);
        }
        
        return res;
    }
};