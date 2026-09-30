class Solution {
    struct Line {
        long long a, b;
        int partCount;

        long long getY(long long x) const {
            return a * x + b;
        }
    };

    bool l2NotNeeded(Line &l1, Line &l2, Line &l3) {
        return (long double)(l2.b - l1.b) * (l2.a - l3.a) >= (long double)(l3.b - l2.b) * (l1.a - l2.a);
    }

    pair<long long, int> getRes(const vector<long long> &p, long long penalty) {
        long long resScore;
        int resPartCount;

        deque<Line> lines = { { 0, 0, 0 } };
        for (long long curP : p) {
            while (lines.size() >= 2 && lines[0].getY(curP) >= lines[1].getY(curP))
                lines.pop_front();

            resScore = lines[0].getY(curP) + curP * (curP + 1) / 2 + penalty;
            resPartCount = lines[0].partCount + 1;

            Line line = { -curP, resScore + curP * (curP - 1) / 2, resPartCount };
            while (lines.size() >= 2 && l2NotNeeded(lines[lines.size() - 2], lines.back(), line))
                lines.pop_back();
            lines.push_back(line);
        }

        return { resScore, resPartCount };
    }

public:
    long long minPartitionScore(vector<int> &a, int partCount) {
        vector<long long> p(a.size());
        partial_sum(a.begin(), a.end(), p.begin());

        long long l = 0, r = 1e18;
        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            if (getRes(p, m).second >= partCount)
                l = m;
            else
                r = m;
        }
        return getRes(p, l).first - l * partCount;
    }
};