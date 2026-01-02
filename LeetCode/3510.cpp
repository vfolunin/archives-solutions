struct SparseArray {
    map<int, long long> storage;
    map<long long, set<int>> q;
    int badPairCount = 0;

    SparseArray(const vector<int> &a) {
        for (int i = 0; i < a.size(); i++) {
            storage[i] = a[i];
            if (i + 1 < a.size()) {
                q[a[i] + a[i + 1]].insert(i);
                badPairCount += a[i] > a[i + 1];
            }
        }
    }

    void eraseFromQ(long long sum, int i) {
        q[sum].erase(i);
        if (q[sum].empty())
            q.erase(sum);
    }

    void eraseMinPair() {
        int i = *q.begin()->second.begin();

        auto it = storage.find(i);
        auto lIt = it != storage.begin() ? prev(it) : storage.end();
        auto rIt = next(it);
        auto rrIt = rIt != storage.end() ? next(rIt) : storage.end();
        
        if (lIt != storage.end()) {
            eraseFromQ(lIt->second + it->second, lIt->first);
            badPairCount -= lIt->second > it->second;
        }
        eraseFromQ(it->second + rIt->second, it->first);
        badPairCount -= it->second > rIt->second;
        if (rrIt != storage.end()) {
            eraseFromQ(rIt->second + rrIt->second, rIt->first);
            badPairCount -= rIt->second > rrIt->second;
        }

        it->second += rIt->second;
        storage.erase(rIt);
        
        if (lIt != storage.end()) {
            q[lIt->second + it->second].insert(lIt->first);
            badPairCount += lIt->second > it->second;
        }
        if (rrIt != storage.end()) {
            q[it->second + rrIt->second].insert(it->first);
            badPairCount += it->second > rrIt->second;
        }
    }
};

class Solution {
public:
    int minimumPairRemoval(vector<int> &a) {
        SparseArray sparseArray(a);
        int res = 0;
        while (sparseArray.badPairCount) {
            sparseArray.eraseMinPair();
            res++;
        }
        return res;
    }
};