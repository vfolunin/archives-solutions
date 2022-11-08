class Solution {
public:
    int profitableSchemes(int weightLimit, int bonusLimit, vector<int> &weight, vector<int> &bonus) {
        const long long MOD = 1e9 + 7;
        
        vector<vector<vector<long long>>> ways(2, vector<vector<long long>>(weightLimit + 1, vector<long long>(bonusLimit + 1)));
        ways[0][0][0] = 1;
        
        for (int i = 0; i < weight.size(); i++) {
            for (int wi = 0; wi <= weightLimit; wi++) {
                for (int bi = 0; bi <= bonusLimit; bi++) {
                    ways[1][wi][bi] = (ways[1][wi][bi] + ways[0][wi][bi]) % MOD;
                    
                    int nwi = wi + weight[i], nbi = min(bi + bonus[i], bonusLimit);
                    if (nwi <= weightLimit)
                        ways[1][nwi][nbi] = (ways[1][nwi][nbi] + ways[0][wi][bi]) % MOD;
                }
            }
            
            ways[0] = ways[1];
            ways[1].assign(weightLimit + 1, vector<long long>(bonusLimit + 1));
        }
        
        long long res = 0;
        for (int wi = 0; wi <= weightLimit; wi++)
            res = (res + ways[0][wi][bonusLimit]) % MOD;
        return res;
    }
};