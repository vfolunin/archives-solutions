class Solution {
public:
    int countCompleteDayPairs(vector<int> &a) {
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            for (int j = i + 1; j < a.size(); j++)
                res += (a[i] + a[j]) % 24 == 0;
        return res;
    }
};