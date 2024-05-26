class Solution {
public:
    int duplicateNumbersXOR(vector<int> &a) {
        sort(a.begin(), a.end());

        int res = 0;
        for (int i = 0; i + 1 < a.size(); i++)
            if (a[i] == a[i + 1])
                res ^= a[i];
        return res;
    }
};