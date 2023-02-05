class Solution {
    long long sum(int to) {
        return to * (to + 1LL) / 2;
    }

    int bannedCount(vector<int> &banned, int to) {
        return lower_bound(banned.begin(), banned.end(), to) - banned.begin();
    }

    long long bannedSum(vector<int> &banned, vector<long long> &pBanned, int to) {
        int count = bannedCount(banned, to);
        return count ? pBanned[count - 1] : 0;
    }

    bool can(vector<int> &banned, vector<long long> pBanned, int to, long long sumLimit) {
        return sum(to) - bannedSum(banned, pBanned, to) <= sumLimit;
    }

public:
    int maxCount(vector<int> &banned, int valueLimit, long long sumLimit) {
        sort(banned.begin(), banned.end());

        vector<long long> pBanned(banned.begin(), banned.end());
        partial_sum(pBanned.begin(), pBanned.end(), pBanned.begin());

        int l = 0, r = valueLimit + 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(banned, pBanned, m, sumLimit))
                l = m;
            else
                r = m;
        }

        return l - bannedCount(banned, l);
    }
};