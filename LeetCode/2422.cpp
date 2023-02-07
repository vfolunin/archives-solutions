class Solution {
public:
    int minimumOperations(vector<int> &a) {
        deque<long long> d(a.begin(), a.end());
        int res = 0;

        while (d.size() > 1) {
            while (d.front() < d.back()) {
                res++;
                d[1] += d.front();
                d.pop_front();
            }

            while (d.back() < d.front()) {
                res++;
                d[d.size() - 2] += d.back();
                d.pop_back();
            }

            if (d.front() == d.back()) {
                d.pop_front();
                if (d.size() > 1)
                    d.pop_back();
            }
        }

        return res;
    }
};