struct QueueWithMaximum {
    deque<long long> values, maximums;

    void push(long long value) {
        values.push_back(value);
        while (!maximums.empty() && maximums.back() < value)
            maximums.pop_back();
        maximums.push_back(value);
    }

    void pop() {
        if (values.front() == maximums.front())
            maximums.pop_front();
        values.pop_front();
    }

    long long getMax() {
        return maximums.front();
    }

    int size() {
        return values.size();
    }
};

class Solution {
public:
    long long maximumSum(vector<int> &a, int partCount, int l, int r) {
        vector<long long> p(a.begin(), a.end());
        partial_sum(p.begin(), p.end(), p.begin());

        vector<vector<long long>> maxSum(partCount + 1, vector<long long>(a.size() + 1, -1e18));
        maxSum[0].assign(a.size() + 1, 0);
        long long res = -1e18;

        for (int parts = 1; parts <= partCount; parts++) {
            QueueWithMaximum q;
            for (int size = parts * l; size <= a.size(); size++) {
                q.push(maxSum[parts - 1][size - l] - (size > l ? p[size - l - 1] : 0));
                if (q.size() > r - l + 1)
                    q.pop();
                maxSum[parts][size] = max(maxSum[parts][size - 1], p[size - 1] + q.getMax());
                res = max(res, maxSum[parts][size]);
            }
        }

        return res;
    }
};