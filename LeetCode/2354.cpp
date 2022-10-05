class Solution {
    int ones(int n) {
        int res = 0;
        while (n) {
            res++;
            n &= n - 1;
        }
        return res;
    }
    
public:
    long long countExcellentPairs(vector<int> &a, int limit) {
        vector<unordered_set<int>> group(31);
        for (int value : a)
            group[ones(value)].insert(value);
        
        long long res = 0;        
        for (int i = 0; i < group.size(); i++)
            for (int j = 0; j < group.size(); j++)
                if (i + j >= limit)
                    res += group[i].size() * group[j].size();        
        return res;
    }
};