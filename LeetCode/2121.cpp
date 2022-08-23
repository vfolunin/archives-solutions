class Solution {
public:
    vector<long long> getDistances(vector<int> &a) {
        unordered_map<int, long long> lPosCount, lPosSum, rPosCount, rPosSum;
        
        for (int i = 0; i < a.size(); i++) {
            rPosCount[a[i]]++;
            rPosSum[a[i]] += i;
        }
        
        vector<long long> res(a.size());
        
        for (int i = 0; i < a.size(); i++) {
            rPosCount[a[i]]--;
            rPosSum[a[i]] -= i;
            
            res[i] = rPosSum[a[i]] - i * rPosCount[a[i]] + i * lPosCount[a[i]] - lPosSum[a[i]];
            
            lPosCount[a[i]]++;
            lPosSum[a[i]] += i;
        }
        
        return res;
    }
};