class Solution {
public:
    long long minimumCost(string &a, string &b, vector<string> &sa, vector<string> &sb, vector<int> &price) {
        unordered_map<string, int> id;
        for (const vector<string> &ss : { sa, sb })
            for (const string &s : ss)
                if (!id.count(s))
                    id[s] = id.size();

        vector<vector<long long>> cost(id.size(), vector<long long>(id.size(), 1e18));
        for (int v = 0; v < id.size(); v++)
            cost[v][v] = 0;

        for (int i = 0; i < sa.size(); i++) {
            int a = id[sa[i]];
            int b = id[sb[i]];
            cost[a][b] = min<long long>(cost[a][b], price[i]);
        }
        
        for (int v = 0; v < id.size(); v++)
            for (int a = 0; a < id.size(); a++)
                for (int b = 0; b < id.size(); b++)
                    cost[a][b] = min(cost[a][b], cost[a][v] + cost[v][b]);
        
        unordered_set<int> lengths = { 1 };
        for (string &s : sa)
            lengths.insert(s.size());

        vector<long long> res(a.size() + 1, 1e18);
        res[0] = 0;

        for (int i = 1; i <= a.size(); i++) {
            for (int len : lengths) {
                if (i >= len) {
                    string sa = a.substr(i - len, len);
                    string sb = b.substr(i - len, len);
                    if (sa == sb)
                        res[i] = min(res[i], res[i - len]);
                    if (id.count(sa) && id.count(sb))
                        res[i] = min(res[i], res[i - len] + cost[id[sa]][id[sb]]);
                }
            }
        }

        return res.back() != 1e18 ? res.back() : -1;
    }
};