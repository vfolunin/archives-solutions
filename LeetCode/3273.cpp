class Solution {
public:
    long long minDamage(int power, vector<int> &damage, vector<int> &health) {
        vector<long long> time(damage.size());
        for (int i = 0; i < time.size(); i++)
            time[i] = (health[i] + power - 1LL) / power;

        vector<int> order(damage.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return time[a] * damage[b] < time[b] * damage[a];
        });

        long long totalDamage = accumulate(damage.begin(), damage.end(), 0LL);
        long long res = 0;
        for (int i : order) {
            res += (health[i] + power - 1LL) / power * totalDamage;
            totalDamage -= damage[i];
        }
        return res;
    }
};