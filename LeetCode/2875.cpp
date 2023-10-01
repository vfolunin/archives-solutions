class Solution {
public:
    int minSizeSubarray(vector<int> &a, int targetSum) {
        long long sum = accumulate(a.begin(), a.end(), 0LL);        
        int resWhole = targetSum / sum * a.size();
        if (targetSum % sum == 0)
            return resWhole;

        targetSum %= sum;        
        a.insert(a.end(), a.begin(), a.end());
        int resEnds = 2e9;

        unordered_map<long long, int> last = { { 0, -1 } };
        long long prefixSum = 0;
        for (int i = 0; i < a.size(); i++) {
            prefixSum += a[i];
            if (auto it = last.find(prefixSum - targetSum); it != last.end())
                resEnds = min(resEnds, i - it->second);
            last[prefixSum] = i;
        }

        return resEnds != 2e9 ? resWhole + resEnds : -1;
    }
};