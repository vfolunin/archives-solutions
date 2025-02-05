class Solution {
public:
    long long numberOfSubsequences(vector<int> &a) {
        unordered_map<double, int> count;
        for (int j = 4; j < a.size(); j++)
            for (int i = j + 2; i < a.size(); i++)
                count[(double)a[i] / a[j]]++;
        
        long long res = 0;
        for (int j = 2; j + 4 < a.size(); j++) {
            for (int i = 0; i + 1 < j; i++)
                res += count[(double)a[i] / a[j]];
            
            for (int i = j + 4; i < a.size(); i++)
                count[(double)a[i] / a[j + 2]]--;
        }
        return res;
    }
};