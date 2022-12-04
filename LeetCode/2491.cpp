class Solution {
public:
    long long dividePlayers(vector<int> &a) {
        sort(a.begin(), a.end());
        int sum = a.front() + a.back();
        
        long long res = 0;
        for (int l = 0, r = a.size() - 1; l < r; l++, r--) {
            if (a[l] + a[r] != sum)
                return -1;
            res += 1LL * a[l] * a[r];
        }
        return res;
    }
};