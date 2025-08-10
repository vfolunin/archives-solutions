class Solution {
public:
    int sortPermutation(vector<int> &a) {
        vector<int> sortedA = a;
        sort(sortedA.begin(), sortedA.end());

        int res = -1;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != sortedA[i])
                res &= a[i];
        return max(res, 0);
    }
};