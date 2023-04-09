class Solution {
    bool can(vector<int> &a, int pairNeed, int dist) {
        vector<int> pairCount(a.size() + 1);
        for (int i = 2; i <= a.size(); i++) {
            pairCount[i] = pairCount[i - 1];
            if (a[i - 1] - a[i - 2] <= dist)
                pairCount[i] = max(pairCount[i], pairCount[i - 2] + 1);
        }
        return pairCount.back() >= pairNeed;
    }
    
public:
    int minimizeMax(vector<int> &a, int pairNeed) {
        sort(a.begin(), a.end());
        
        int l = -1, r = 1e9 + 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(a, pairNeed, m))
                r = m;
            else
                l = m;
        }
        
        return r;
    }
};