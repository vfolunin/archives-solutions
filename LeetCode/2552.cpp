class Solution {
public:
    long long countQuadruplets(vector<int> &a) {
        for (int &value : a)
            value--;
        
        vector<vector<long long>> l(a.size(), vector<long long>(a.size()));
        for (int i = 1; i < a.size(); i++) {
            l[i] = l[i - 1];
            l[i][a[i - 1]] = 1;
        }
        for (int i = 0; i < a.size(); i++)
            partial_sum(l[i].begin(), l[i].end(), l[i].begin());
        
        vector<vector<long long>> r(a.size(), vector<long long>(a.size()));
        for (int i = (int)a.size() - 2; i >= 0; i--) {
            r[i] = r[i + 1];
            r[i][a[i + 1]] = 1;
        }
        for (int i = 0; i < a.size(); i++)
            partial_sum(r[i].rbegin(), r[i].rend(), r[i].rbegin());
        
        long long res = 0;
        for (int li = 0; li < a.size(); li++)
            for (int ri = li + 1; ri < a.size(); ri++)
                if (a[ri] < a[li])
                    res += l[li][a[ri]] * r[ri][a[li]];
        
        return res;
    }
};