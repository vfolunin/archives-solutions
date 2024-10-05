class Solution {
    bool can(int count, int upgrade, int sell, int money, int upgradeCount) {
        return (money + 1LL * sell * (count - upgradeCount)) / upgrade >= upgradeCount;
    }
    
public:
    vector<int> maxUpgrades(vector<int> &count, vector<int> &upgrade, vector<int> &sell, vector<int> &money) {
        vector<int> res(count.size());
        for (int i = 0; i < res.size(); i++) {
            int l = 0, r = count[i] + 1;
            while (l + 1 < r) {
                int m = l + (r - l) / 2;
                if (can(count[i], upgrade[i], sell[i], money[i], m))
                    l = m;
                else
                    r = m;
            }
            res[i] = l;
        }
        return res;
    }
};