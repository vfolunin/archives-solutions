class Solution {
public:
    vector<int> assignElements(vector<int> &num, vector<int> &den) {
        vector<vector<int>> pos(1e5 + 1);
        for (int i = 0; i < num.size(); i++)
            pos[num[i]].push_back(i);
        
        unordered_set<int> seen;
        vector<int> res(num.size(), -1);

        for (int i = 0; i < den.size(); i++) {
            if (seen.count(den[i]))
                continue;
            seen.insert(den[i]);

            for (int factor = den[i]; factor <= 1e5; factor += den[i])
                for (int j : pos[factor])
                    if (res[j] == -1)
                        res[j] = i;
        }

        return res;
    }
};