class Solution {
    int rearrange(int value) {
        string s = to_string(value);
        sort(s.rbegin(), s.rend());
        return stoi(s);
    }

public:
    long long maximizeSum(vector<int> &a, int opLimit) {
        vector<int> deltas(a.size());
        for (int i = 0; i < a.size(); i++)
            deltas[i] = rearrange(a[i]) - a[i];
        sort(deltas.rbegin(), deltas.rend());

        return accumulate(a.begin(), a.end(), 0LL) + accumulate(deltas.begin(), deltas.begin() + opLimit, 0LL);
    }
};