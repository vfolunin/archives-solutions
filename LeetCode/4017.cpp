struct BIT {
    vector<long long> f;

    BIT(int size) : f(size) {}

    long long sum(int r) {
        long long res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            res += f[r];
        return res;
    }

    long long sum(int l, int r) {
        return sum(r) - (l ? sum(l - 1) : 0);
    }

    void add(int i, long long v) {
        for (; i < f.size(); i |= i + 1)
            f[i] += v;
    }

    void set(int i, long long v) {
        add(i, v - sum(i, i));
    }
};

struct PeakSet {
    set<int> peaks;
    BIT bit;

    PeakSet() : bit(1e5) {}

    void insertPeak(int pos) {
        auto it = peaks.insert(pos).first;
        
        long long lPos = it == peaks.begin() ? 0 : *prev(it);
        bit.set(pos, pos * (pos - lPos));

        if (auto rIt = next(it); rIt != peaks.end()) {
            long long rPos = *rIt;
            bit.set(rPos, rPos * (rPos - pos));
        }
    }

    void erasePeak(int pos) {
        peaks.erase(pos);
        bit.set(pos, 0);

        if (auto rIt = peaks.upper_bound(pos); rIt != peaks.end()) {
            long long lPos = rIt == peaks.begin() ? 0 : *prev(rIt);
            long long rPos = *rIt;
            bit.set(rPos, rPos * (rPos - lPos));
        }
    }

    long long getPeakCount(int l, int r) {
        auto lIt = peaks.lower_bound(l);
        if (lIt == peaks.end() || r < *lIt) 
            return 0;
        auto rIt = prev(peaks.upper_bound(r));

        long long pPos = lIt == peaks.begin() ? 0 : *prev(lIt);
        long long lPos = *lIt;
        long long rPos = *rIt;
        return lPos * (l - pPos) - bit.sum(lPos, rPos) + r * (rPos - l);
    }
};

class Solution {
    bool checkPeak(vector<int> &values, int i) {
        return 0 < i && i + 1 < values.size() && values[i - 1] < values[i] && values[i] > values[i + 1];
    }

public:
    vector<long long> countOfPeaks(vector<int> &values, vector<vector<int>> &queries) {
        PeakSet peakSet;
        for (int i = 1; i + 1 < values.size(); i++)
            if (checkPeak(values, i))
                peakSet.insertPeak(i);

        vector<long long> res;
        for (vector<int> &query : queries) {
            if (query[0] == 1) {
                int l = query[1], r = query[2];

                res.push_back(peakSet.getPeakCount(l, r));
            } else {
                int pos = query[1], value = query[2];

                for (int i : { pos - 1, pos, pos + 1 })
                    if (checkPeak(values, i))
                        peakSet.erasePeak(i);

                values[pos] = value;

                for (int i : { pos - 1, pos, pos + 1 })
                    if (checkPeak(values, i))
                        peakSet.insertPeak(i);
            }
        }
        return res;
    }
};