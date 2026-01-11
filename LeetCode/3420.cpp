class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int> &a, int opLimit) {
        reverse(a.begin(), a.end());

        long long ops = 0, res = 0;
        deque<pair<int, int>> q;

        for (int l = 0, r = 0; r < a.size(); r++) {
            int rValue = a[r];
            int rCount = 1;

            while (!q.empty() && q.back().first < rValue) {
                auto [qrValue, qrCount] = q.back();
                q.pop_back();

                ops += 1LL * (rValue - qrValue) * qrCount;
                rCount += qrCount;
            }
            q.push_back({ rValue, rCount });

            for (; ops > opLimit; l++) {
                auto [qlValue, qlCount] = q.front();
                q.pop_front();

                ops -= qlValue - a[l];
                if (qlCount > 1)
                    q.push_front({ qlValue, qlCount - 1 });
            }

            res += r - l + 1;
        }

        return res;
    }
};