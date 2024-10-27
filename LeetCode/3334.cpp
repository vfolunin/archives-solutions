class Solution {
public:
    long long maxScore(vector<int> &a) {
        vector<long long> gcdL(a.size()), lcmL(a.size(), 1);
        for (int i = 1; i < a.size(); i++) {
            gcdL[i] = gcd(gcdL[i - 1], a[i - 1]);
            lcmL[i] = lcm(lcmL[i - 1], a[i - 1]);
        }
        
        vector<long long> gcdR(a.size()), lcmR(a.size(), 1);
        for (int i = (int)a.size() - 2; i >= 0; i--) {
            gcdR[i] = gcd(gcdR[i + 1], a[i + 1]);
            lcmR[i] = lcm(lcmR[i + 1], a[i + 1]);
        }

        long long res = gcd(a[0], gcdR[0]) * lcm(a[0], lcmR[0]);
        for (int i = 0; i < a.size(); i++)
            res = max(res, gcd(gcdL[i], gcdR[i]) * lcm(lcmL[i], lcmR[i]));
        return res;
    }
};