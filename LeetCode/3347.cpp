class Solution {
public:
    int maxFrequency(vector<int> &a, int delta, int opCount) {
        sort(a.begin(), a.end());
        
        vector<int> values;
        for (int value : a) {
            values.push_back(value - delta);
            values.push_back(value);
            values.push_back(value + delta);
        }
        sort(values.begin(), values.end());

        int l = 0, le = 0, re = 0, r = 0, res = 0;
        for (int value : values) {
            while (l < a.size() && a[l] < value - delta)
                l++;
            while (le < a.size() && a[le] < value)
                le++;
            while (re < a.size() && a[re] <= value)
                re++;
            while (r < a.size() && a[r] <= value + delta)
                r++;

            int equalCount = re - le;
            int changedCount = min(r - l - equalCount, opCount);
            res = max(res, equalCount + changedCount);
        }
        return res;
    }
};