class Solution {
public:
    long long maxCaloriesBurnt(vector<int> &a) {
        a.push_back(0);
        sort(a.begin(), a.end());

        long long res = 0;
        for (int l = 0, r = a.size() - 1; l < r; ) {
            res += 1LL * (a[l] - a[r]) * (a[l] - a[r]);
            l++;
            res += 1LL * (a[l] - a[r]) * (a[l] - a[r]);
            r--;
        }
        return res;
    }
};