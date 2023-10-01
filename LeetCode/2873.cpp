class Solution {
public:
    long long maximumTripletValue(vector<int> &a) {
        long long res = 0;
        for (int i = 0; i < a.size(); i++)
            for (int j = i + 1; j < a.size(); j++)
                for (int k = j + 1; k < a.size(); k++)
                    res = max(res, 1LL * (a[i] - a[j]) * a[k]);
        return res;
    }
};