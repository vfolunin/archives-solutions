class Solution {
public:
    int kthSmallest(vector<vector<int>> &a, int k) {
        int sum = 0;
        for (int i = 0; i < a.size(); i++)
            sum += a[i][0];
        
        set<pair<int, vector<int>>> sums = { { sum, vector<int>(a.size()) } };
        
        for (int i = 0; i < k - 1; i++) {
            auto [sum, indexes] = *sums.begin();
            sums.erase(sums.begin());
            
            for (int j = 0; j < a.size(); j++) {
                if (indexes[j] + 1 < a[j].size()) {
                    sum += a[j][indexes[j] + 1] - a[j][indexes[j]];
                    indexes[j]++;
                    
                    sums.insert({ sum, indexes });
                    if (sums.size() > k)
                        sums.erase(--sums.end());
                    
                    sum += a[j][indexes[j] - 1] - a[j][indexes[j]];
                    indexes[j]--;                    
                }
            }
        }
        
        return sums.begin()->first;
    }
};