class Solution {
public:
    long long countFairPairs(vector<int> &a, int lower, int upper) {
        sort(a.begin(), a.end());
        long long res = 0;

        for (int l = 0, r1 = a.size() - 1, r2 = a.size() - 1; l < a.size(); l++) {
            while (r1 >= 0 && a[l] + a[r1] >= lower)
                r1--;
                
            while (r2 >= 0 && a[l] + a[r2] > upper)
                r2--;

            if (l < r2)
                res += r2 - max(l, r1);
        }

        return res;
    }
};