class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &a) {
        vector<unordered_map<long long, long long>> ways(a.size());
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < i; j++) {
                long long d = (long long)a[i] - a[j];
                ways[i][d]++;
                if (ways[j].count(d))
                    ways[i][d] += ways[j][d];
            }
        }
        
        long long res = 0;
        for (int i = 0; i < a.size(); i++)
            for (auto &[d, count] : ways[i])
                res += count;
        res -= a.size() * (a.size() - 1) / 2;
        
        return res;
    }
};