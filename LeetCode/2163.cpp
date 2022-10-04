class Solution {
public:
    long long minimumDifference(vector<int> &a) {
        int k = a.size() / 3;
        
        multiset<int> window = { a.begin(), a.begin() + k };
        long long windowSum = accumulate(a.begin(), a.begin() + k, 0LL);
        vector<long long> l(a.size());
        l[k - 1] = windowSum;
        
        for (int i = k; i < a.size(); i++) {
            windowSum += a[i];
            window.insert(a[i]);
            windowSum -= *prev(window.end());
            window.erase(prev(window.end()));
            l[i] = windowSum;
        }
        
        window = { a.rbegin(), a.rbegin() + k };
        windowSum = accumulate(a.rbegin(), a.rbegin() + k, 0LL);
        vector<long long> r(a.size());
        r[a.size() - k] = windowSum;
        
        for (int i = a.size() - k - 1; i >= 0; i--) {
            windowSum += a[i];
            window.insert(a[i]);
            windowSum -= *window.begin();
            window.erase(window.begin());
            r[i] = windowSum;
        }
        
        long long res = l[k - 1] - r[k];
        for (int i = k; i + k < a.size(); i++)
            res = min(res, l[i] - r[i + 1]);
        return res;
    }
};