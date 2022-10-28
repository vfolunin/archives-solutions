class Solution {
    long long getCount(vector<int> &a, int dist) {
        long long res = 0;
        for (int l = 0, r = 0; l < a.size(); l++) {
            while (r < a.size() && a[r] - a[l] < dist)
                r++;
            res += r - l - 1;
        }
        return res;
    }
    
public:
    int smallestDistancePair(vector<int> &a, int k) {
        sort(a.begin(), a.end());
        k--;
        
        int l = -1, r = 1e9;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (getCount(a, m) <= k)
                l = m;
            else
                r = m;
        }        
        return l;
    }
};