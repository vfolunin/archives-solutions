class Solution {
public:
    long long findMaximumScore(vector<int> &a) {
        long long res = 0;

        for (int i = 0; i + 1 < a.size(); ) {
            int j = i;
            while (j + 1 < a.size() && a[j] <= a[i])
                j++;
            
            res += 1LL * (j - i) * a[i];

            i = j;
        }

        return res;
    }
};