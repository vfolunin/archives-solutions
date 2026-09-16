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

    void add(int i, int delta) {
        for (; i < f.size(); i |= i + 1)
            f[i] += delta;
    }
};

class Solution {
public:
    long long shadowPairs(vector<int> &a) {
        vector<int> r(a.size(), a.size()), stack;
        for (int i = 0; i < a.size(); i++) {
            while (!stack.empty() && a[stack.back()] > a[i]) {
                r[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }

        map<int, vector<int>> pos;
        for (int i = 0; i < a.size(); i++)
            pos[a[i]].push_back(i);

        BIT fenwickTree(a.size() + 1);
        long long res = 0;
        for (auto it = pos.rbegin(); it != pos.rend(); it++) {
            auto &[value, valuePos] = *it;

            for (int i : valuePos)
                res += fenwickTree.sum(i, r[i]);
            
            for (int i : valuePos)
                fenwickTree.add(i, 1);
        }
        return res;
    }
};