class Solution {
    bool can(vector<int> &a, vector<int> &pos, int limit) {
        long long opCount = accumulate(a.begin(), a.end(), 0LL) + a.size(), slotCount = 0;
        multiset<int> nullifiedValues;

        for (int time = limit - 1; time >= 0; time--) {
            if (pos[time] == -1) {
                slotCount++;
            } else {
                opCount -= a[pos[time]] + 1;
                nullifiedValues.insert(a[pos[time]]);

                if (slotCount) {
                    slotCount--;
                } else {
                    opCount += *nullifiedValues.begin() + 1;
                    nullifiedValues.erase(nullifiedValues.begin());
                    slotCount++;
                }
            }
        }

        return opCount <= slotCount;
    }

public:
    int earliestSecondToMarkIndices(vector<int> &a, vector<int> &pos) {
        unordered_set<int> nullifiedPos;
        for (int &pos : pos) {
            pos--;
            if (a[pos] > 1 && !nullifiedPos.count(pos))
                nullifiedPos.insert(pos);
            else
                pos = -1;
        }

        int l = 0, r = pos.size() + 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(a, pos, m))
                r = m;
            else
                l = m;
        }
        return r <= pos.size() ? r : -1;
    }
};