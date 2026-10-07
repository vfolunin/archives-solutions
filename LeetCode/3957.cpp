class Solution {
    long long getSum(const vector<long long> &p, int l, int r) {
        if (l > r)
            return 0;
        return p[r] - (l ? p[l - 1] : 0);
    }

    long long getOnePartRes(const vector<long long> &p, int minPartSize, int maxPartSize) {
        long long res = -1e18;

        deque<int> prevSizes;
        for (int size = minPartSize; size <= p.size(); size++) {
            while (!prevSizes.empty() && prevSizes.front() < size - maxPartSize)
                prevSizes.pop_front();

            int prevSize = size - minPartSize;
            while (!prevSizes.empty() && getSum(p, 0, prevSizes.back() - 1) >= getSum(p, 0, prevSize - 1))
                prevSizes.pop_back();
            prevSizes.push_back(prevSize);

            res = max(res, getSum(p, prevSizes.front(), size - 1));
        }

        return res;
    }

    pair<long long, int> getRes(const vector<long long> &p, int minPartSize, int maxPartSize, long long penalty) {
        vector<pair<long long, int>> res(p.size() + 1);

        deque<int> prevSizes;
        for (int size = 1; size <= p.size(); size++) {
            res[size] = res[size - 1];

            while (!prevSizes.empty() && prevSizes.front() < size - maxPartSize)
                prevSizes.pop_front();

            int prevSize = size - minPartSize;
            if (prevSize >= 0) {
                long long curSum = res[prevSize].first + getSum(p, prevSize, size - 1) - penalty;
                int curPartCount = res[prevSize].second + 1;

                while (!prevSizes.empty()) {
                    long long lastSum = res[prevSizes.back()].first + getSum(p, prevSizes.back(), size - 1) - penalty;
                    int lastPairCount = res[prevSizes.back()].second + 1;
                    if (pair(lastSum, lastPairCount) <= pair(curSum, curPartCount))
                        prevSizes.pop_back();
                    else
                        break;
                }

                prevSizes.push_back(prevSize);
            }

            if (!prevSizes.empty()) {
                long long curSum = res[prevSizes.front()].first + getSum(p, prevSizes.front(), size - 1) - penalty;
                int curPartCount = res[prevSizes.front()].second + 1;
                res[size] = max(res[size], pair(curSum, curPartCount));
            }
        }

        return res[p.size()];
    }

public:
    long long maximumSum(vector<int> &a, int maxPartCount, int minPartSize, int maxPartSize) {
        vector<long long> p(a.begin(), a.end());
        partial_sum(p.begin(), p.end(), p.begin());

        long long onePartSum = getOnePartRes(p, minPartSize, maxPartSize);
        if (onePartSum <= 0)
            return onePartSum;

        auto [sum, partCount] = getRes(p, minPartSize, maxPartSize, 0);
        if (partCount <= maxPartCount)
            return sum;

        long long l = 0, r = 1;
        while (getRes(p, minPartSize, maxPartSize, r).second >= maxPartCount)
            r *= 2;

        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            if (getRes(p, minPartSize, maxPartSize, m).second >= maxPartCount)
                l = m;
            else
                r = m;
        }

        tie(sum, partCount) = getRes(p, minPartSize, maxPartSize, l);
        return sum + l * min(partCount, maxPartCount);
    }
};