struct TwoSet {
    multiset<int> l, r;
    long long lSum = 0, rSum = 0;

    void rebalance() {
        while (l.size() < r.size()) {
            l.insert(*r.begin());
            lSum += *r.begin();
            rSum -= *r.begin();
            r.erase(r.begin());
        }
        while (l.size() > r.size() + 1) {
            r.insert(*prev(l.end()));
            lSum -= *prev(l.end());
            rSum += *prev(l.end());
            l.erase(prev(l.end()));
        }
    }

    void insert(int value) {
        if (l.empty() || value <= *prev(l.end())) {
            l.insert(value);
            lSum += value;
        } else {
            r.insert(value);
            rSum += value;
        }
        rebalance();
    }

    void erase(int value) {
        if (auto it = l.find(value); it != l.end()) {
            l.erase(it);
            lSum -= value;
        } else {
            r.erase(r.find(value));
            rSum -= value;
        }
        rebalance();
    }

    long long getPrice() {
        int value = *prev(l.end());
        return l.size() * value - lSum + rSum - r.size() * value;
    }
};

class Solution {
public:
    long long minOperations(vector<int> &a, int partSize, int partCount) {
        TwoSet values;
        for (int i = 0; i < partSize; i++)
            values.insert(a[i]);

        vector<long long> price(a.size(), 1e18);
        price[partSize - 1] = values.getPrice();
        
        for (int i = partSize; i < a.size(); i++) {
            values.erase(a[i - partSize]);
            values.insert(a[i]);
            price[i] = values.getPrice();
        }

        vector<vector<long long>> cost(partCount + 1, vector<long long>(a.size(), 1e18));
        fill(cost[0].begin(), cost[0].end(), 0);
        
        for (int count = 1; count <= partCount; count++) {
            for (int i = count * partSize - 1; i < a.size(); i++) {
                cost[count][i] = price[i] + (count > 1 ? cost[count - 1][i - partSize] : 0);
                if (i >= count * partSize)
                    cost[count][i] = min(cost[count][i], cost[count][i - 1]);
            }
        }

        return cost.back().back();
    }
};