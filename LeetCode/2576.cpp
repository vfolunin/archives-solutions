class Solution {
    bool can(vector<int> &a, int pairCount) {
        if (pairCount * 2 > a.size())
            return 0;

        for (int l = 0, r = a.size() - pairCount; l < pairCount; l++, r++)
            if (a[l] * 2 > a[r])
                return 0;

        return 1;
    }
    
public:
    int maxNumOfMarkedIndices(vector<int> &a) {
        sort(a.begin(), a.end());
        
        int l = 0, r = a.size() / 2 + 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(a, m))
                l = m;
            else
                r = m;
        }
        return l * 2;
    }
};