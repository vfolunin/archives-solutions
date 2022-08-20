class Solution {
public:
    vector<int> platesBetweenCandles(string &s, vector<vector<int>> &queries) {
        vector<int> platePos, candlePos;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*')
                platePos.push_back(i);
            else
                candlePos.push_back(i);
        }
        
        vector<int> res(queries.size());
        
        for (int i = 0; i < res.size(); i++) {
            auto cl = lower_bound(candlePos.begin(), candlePos.end(), queries[i][0]);
            auto cr = upper_bound(candlePos.begin(), candlePos.end(), queries[i][1]);
            if (cr > candlePos.begin())
                cr--;
            if (cl >= cr)
                continue;
            
            auto pl = lower_bound(platePos.begin(), platePos.end(), *cl);
            auto pr = prev(upper_bound(platePos.begin(), platePos.end(), *cr));
            if (pl > pr)
                continue;
            
            res[i] = pr - pl + 1;
        }
        
        return res;
    }
};