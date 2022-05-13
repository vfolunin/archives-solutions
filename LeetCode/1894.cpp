class Solution {
public:
    int chalkReplacer(vector<int> &a, int k) {
        k %= accumulate(a.begin(), a.end(), 0LL);
        for (int i = 0; 1; i++) {
            if (k < a[i])
                return i;
            k -= a[i];
        }
    }
};