class Solution {
public:
    int maxSumRangeQuery(vector<int> &a, vector<vector<int>> &requests) {
        vector<int> count(a.size());
        for (vector<int> &request : requests) {
            count[request[0]]++;
            if (request[1] + 1 < a.size())
                count[request[1] + 1]--;
        }
        
        partial_sum(count.begin(), count.end(), count.begin());
        sort(count.begin(), count.end());
        sort(a.begin(), a.end());
        
        long long res = 0;
        const long long MOD = 1e9 + 7;
        
        for (int i = 0; i < count.size(); i++)
            res = (res + 1LL * a[i] * count[i]) % MOD;
        
        return res;
    }
};