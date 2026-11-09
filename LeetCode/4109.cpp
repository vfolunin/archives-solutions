struct Counter {
    unordered_map<int, int> count;
    int nonzeroCount = 0;

    void add(int value, int delta) {
        nonzeroCount -= count[value] != 0;
        count[value] += delta;
        nonzeroCount += count[value] != 0;
    }

    bool isOk() {
        return !nonzeroCount;
    }
};

class Solution {
    vector<int> zFunction(vector<int> &s) {
        vector<int> z(s.size());

        int blockL = 0, blockR = 0;
        for (int i = 1; i < s.size(); i++) {
            int blockLen = 0;

            if (i <= blockR)
                blockLen = min(z[i - blockL], blockR - i + 1);

            while (i + blockLen < s.size() &&
                   s[i + blockLen] == s[blockLen])
                blockLen++;

            z[i] = blockLen;

            if (blockR < i + blockLen - 1) {
                blockL = i;
                blockR = i + blockLen - 1;
            }
        }

        return z;
    }

public:
    vector<int> countSuffix(vector<int> &a, vector<int> &b) {
        vector<int> text = a;
        text.push_back(0);
        text.insert(text.end(), b.begin(), b.end());
        vector<int> z = zFunction(text);

        Counter counter;
        for (int value : a)
            counter.add(value, -1);

        int lastUpPos = 0;
        for (int i = 0; i < a.size(); i++) {
            counter.add(b[i], 1);

            if (i && b[i - 1] < b[i])
                lastUpPos = i;
        }

        vector<int> res(b.size() - a.size() + 1);

        for (int l = 0, r = a.size() - 1; r < b.size(); l++, r++) {
            if (l > 0) {
                counter.add(b[l - 1], -1);
                counter.add(b[r], 1);

                if (b[r - 1] < b[r])
                    lastUpPos = r;
            }

            if (!counter.isOk())
                continue;

            int minPos = max(lastUpPos - l, 0);
            int maxPos = min<int>(z[a.size() + 1 + l], a.size() - 1);
            res[l] = max(maxPos - minPos + 1, 0);
        }

        return res;
    }
};