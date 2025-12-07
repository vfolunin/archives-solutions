class Solution {
public:
    long long totalScore(int hp, vector<int> &damage, vector<int> &threshold) {
        vector<long long> pDamage(1);
        for (int value : damage)
            pDamage.push_back(pDamage.back() + value);

        long long res = 0;
        for (int i = 0; i < damage.size(); i++) {
            int value = pDamage[i + 1] + threshold[i] - hp;
            int j = lower_bound(pDamage.begin(), pDamage.end(), value) - pDamage.begin();
            res += max(i - j + 1, 0);
        }
        return res;
    }
};