class Solution {
    vector<long long> makeP(vector<int> &a) {
        vector<long long> p = { a.begin(), a.end() };
        p.insert(p.end(), a.begin(), a.end());
        partial_sum(p.begin(), p.end(), p.begin());
        return p;
    }

    long long getSum(vector<long long> &p, int l, int r) {
        return p[r] - (l ? p[l - 1] : 0);
    }

    long long getDist(vector<long long> &pa, vector<long long> &pb, int from, int to) {
        long long distA = from < to ? getSum(pa, from, to - 1) : getSum(pa, from, to + pa.size() / 2 - 1);
        long long distB = from > to ? getSum(pb, to + 1, from) : getSum(pb, to + 1, from + pb.size() / 2);
        return min(distA, distB);
    }

public:
    long long minTotalTime(vector<int> &a, vector<int> &b, vector<int> &path) {
        vector<long long> pa = makeP(a);
        vector<long long> pb = makeP(b);

        path.insert(path.begin(), 0);

        long long res = 0;
        for (int i = 0; i + 1 < path.size(); i++)
            res += getDist(pa, pb, path[i], path[i + 1]);
        return res;
    }
};