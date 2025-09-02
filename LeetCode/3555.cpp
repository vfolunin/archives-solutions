class Solution {
public:
    vector<int> minSubarraySort(vector<int> &a, int windowSize) {
        vector<int> res(a.size() - windowSize + 1);

        for (int l = 0, r = windowSize - 1; r < a.size(); l++, r++) {
            vector<int> sortedWindow(a.begin() + l, a.begin() + r + 1);
            sort(sortedWindow.begin(), sortedWindow.end());

            int li = 0;
            while (li < sortedWindow.size() && a[l + li] == sortedWindow[li])
                li++;

            int ri = sortedWindow.size() - 1;;
            while (ri >= 0 && a[l + ri] == sortedWindow[ri])
                ri--;
            
            res[l] = max(ri - li + 1, 0);
        }

        return res;
    }
};