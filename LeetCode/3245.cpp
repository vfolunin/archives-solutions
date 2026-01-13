class Counter {
    vector<int> a;
    map<int, int> lenCount;
    set<int> ends;

    void insertLen(int len) {
        lenCount[len]++;
    }

    void eraseLen(int len) {
        if (auto it = lenCount.find(len); !--it->second)
            lenCount.erase(it);
    }

    int getLen(int l, int r) {
        return r + (l < r ? 0 : a.size()) - l;
    }

    void insertEnd(int i) {
        if (ends.empty()) {
            lenCount.clear();
            insertLen(a.size());
        } else if (ends.size() == 1) {
            lenCount.clear();
            insertLen(getLen(i, *ends.begin()));
            insertLen(getLen(*ends.begin(), i));
        } else {
            auto rIt = ends.upper_bound(i);
            if (rIt == ends.end())
                rIt = ends.begin();
            auto lIt = prev(rIt == ends.begin() ? ends.end() : rIt);
            eraseLen(getLen(*lIt, *rIt));
            insertLen(getLen(*lIt, i));
            insertLen(getLen(i, *rIt));
        }
        ends.insert(i);
    }

    void eraseEnd(int i) {
        ends.erase(i);
        if (ends.empty()) {
            lenCount.clear();
            insertLen(2 * a.size());
        } else if (ends.size() == 1) {
            lenCount.clear();
            insertLen(a.size());
        } else {
            auto rIt = ends.upper_bound(i);
            if (rIt == ends.end())
                rIt = ends.begin();
            auto lIt = prev(rIt == ends.begin() ? ends.end() : rIt);
            eraseLen(getLen(*lIt, i));
            eraseLen(getLen(i, *rIt));
            insertLen(getLen(*lIt, *rIt));
        }
    }

public:
    Counter(vector<int> &a) : a(a) {
        lenCount[2 * a.size()] = 1;
        for (int i = 0; i < a.size(); ++i)
            if (a[i] == a[(i + 1) % a.size()])
                insertEnd(i);
    }

    int getCount(int len) {
        int res = 0;
        for (auto it = lenCount.lower_bound(len); it != lenCount.end(); it++)
            res += (it->first - len + 1) * it->second;
        return res;
    }

    void set(int index, int value) {
        if (a[index] == value)
            return;

        auto it = ends.lower_bound(index);
        if (it != end(ends) && *it == index)
            eraseEnd(*it);
        else
            insertEnd(index);

        int prevIndex = (index == 0 ? a.size() : index) - 1;
        if (a[prevIndex] != a[index])
            insertEnd(prevIndex);
        else
            eraseEnd(prevIndex);

        a[index] = value;
    }
};

class Solution {
public:
    vector<int> numberOfAlternatingGroups(vector<int> &a, vector<vector<int>> &queries) {
        Counter counter(a);
        vector<int> res;
        for (vector<int> &query : queries) {
            if (query[0] == 1)
                res.push_back(min<int>(counter.getCount(query[1]), a.size()));
            else
                counter.set(query[1], query[2]);
        }
        return res;
    }
};