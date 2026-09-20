struct FourSets {
    long long sumOut = 0, sumOutMax = 0, sumInMin = 0, sumIn = 0;
    multiset<int> out, outMax, inMin, in;
    int limit;

    FourSets(vector<int> &a, int limit) : limit(limit) {
        for (int value : a) {
            sumOut += value;
            out.insert(value);
        }
    }

    void moveFromOutMaxToOut(int value) {
        sumOutMax -= value;
        sumOut += value;
        out.insert(outMax.extract(outMax.find(value)));
    }

    void moveFromInMinToIn(int value) {
        sumInMin -= value;
        sumIn += value;
        in.insert(inMin.extract(inMin.find(value)));
    }

    void moveFromOutToOutMax(int value) {
        sumOut -= value;
        sumOutMax += value;
        outMax.insert(out.extract(out.find(value)));
    }

    void moveFromInToInMin(int value) {
        sumIn -= value;
        sumInMin += value;
        inMin.insert(in.extract(in.find(value)));
    }

    void rebalance() {
        while (!out.empty() && !outMax.empty() && *prev(out.end()) > *outMax.begin()) {
            moveFromOutToOutMax(*prev(out.end()));
            moveFromOutMaxToOut(*outMax.begin());
        }
        while (!inMin.empty() && !in.empty() && *prev(inMin.end()) > *in.begin()) {
            moveFromInMinToIn(*prev(inMin.end()));
            moveFromInToInMin(*in.begin());
        }
        while (!outMax.empty() && !inMin.empty() && *outMax.begin() < *prev(inMin.end())) {
            moveFromOutMaxToOut(*outMax.begin());
            moveFromInMinToIn(*prev(inMin.end()));
        }
        while (outMax.size() < limit && !in.empty() && !out.empty() && *in.begin() < *prev(out.end())) {
            moveFromOutToOutMax(*prev(out.end()));
            moveFromInToInMin(*in.begin());
        }
    }

    void moveFromOutToIn(int value) {
        if (outMax.contains(value)) {
            moveFromOutMaxToOut(value);
            moveFromInMinToIn(*prev(inMin.end()));
        }
        sumOut -= value;
        sumIn += value;
        in.insert(out.extract(out.find(value)));
        rebalance();
    }

    void moveFromInToOut(int value) {
        if (inMin.contains(value)) {
            moveFromInMinToIn(value);
            moveFromOutMaxToOut(*outMax.begin());
        }
        sumIn -= value;
        sumOut += value;
        out.insert(in.extract(in.find(value)));
        rebalance();
    }

    long long getSum() {
        return sumIn + sumOutMax;
    }
};

class Solution {
public:
    long long maxSum(vector<int> &a, int limit) {
        FourSets container(a, limit);
        long long res = -1e18;

        for (int l = 0; l < a.size(); l++) {
            for (int r = l; r < a.size(); r++) {
                container.moveFromOutToIn(a[r]);
                res = max(res, container.getSum());
            }
            for (int r = l; r < a.size(); r++)
                container.moveFromInToOut(a[r]);
        }

        return res;
    }
};