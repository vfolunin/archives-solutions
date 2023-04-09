class Solution {
public:
    vector<long long> distance(vector<int> &a) {
        unordered_map<int, long long> sumL, sumR, countL, countR;
        for (int i = 0; i < a.size(); i++) {
            sumR[a[i]] += i;
            countR[a[i]]++;
        }
        
        vector<long long> res(a.size());

        for (int i = 0; i < a.size(); i++) {
            sumR[a[i]] -= i;
            countR[a[i]]--;

            res[i] = (sumR[a[i]] - i * countR[a[i]]) + (i * countL[a[i]] - sumL[a[i]]);
            
            sumL[a[i]] += i;
            countL[a[i]]++;
        }
        
        return res;
    }
};