class Solution {
public:
    long long maxKelements(vector<int> &a, int opCount) {
        multiset<int> q(a.begin(), a.end());
        long long res = 0;
        for (int i = 0; i < opCount; i++) {
            int value = *prev(q.end());
            q.erase(prev(q.end()));
            res += value;
            q.insert((value + 2) / 3);
        }
        return res;
    }
};