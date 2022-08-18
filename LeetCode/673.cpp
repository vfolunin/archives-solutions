class Solution {
public:
    int findNumberOfLIS(vector<int> &a) {
        vector<pair<int, int>> lis(a.size(), { 1, 1 });
        int maxSize = 0, maxCount = 0;
        
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (a[i] <= a[j])
                    continue;
                
                if (lis[i].first < lis[j].first + 1)
                    lis[i] = { lis[j].first + 1, lis[j].second };
                else if (lis[i].first == lis[j].first + 1)
                    lis[i].second += lis[j].second;
            }

            if (maxSize < lis[i].first) {
                maxSize = lis[i].first;
                maxCount = lis[i].second;
            } else if (maxSize == lis[i].first) {
                maxCount += lis[i].second;
            }
        }
        
        return maxCount;
    }
};