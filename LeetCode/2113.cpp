class Solution {
public:
    vector<int> elementInNums(vector<int> &a, vector<vector<int>> &queries) {
        vector<int> res(queries.size());

        for (int i = 0; i < queries.size(); i++) {
            int time = queries[i][0] % (a.size() * 2), index = queries[i][1];

            int l = 0, r = a.size() - 1;
            if (time <= a.size())
                l = time;
            if (time >= a.size())
                r = time - a.size() - 1;
                
            res[i] = index < r - l + 1 ? a[l + index] : -1;
        }

        return res;
    }
};