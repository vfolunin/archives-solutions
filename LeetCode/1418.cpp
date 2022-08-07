class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>> &orders) {
        set<int> tables;
        set<string> dishes;
        map<pair<int, string>, int> count;
        
        for (vector<string> &order : orders) {
            int table = stoi(order[1]);
            tables.insert(table);
            dishes.insert(order[2]);
            count[{ table, order[2] }]++;
        }
        
        vector<vector<string>> res = { { "Table" } };
        res.back().insert(res.back().end(), dishes.begin(), dishes.end());
        
        for (int table : tables) {
            res.push_back({ to_string(table) });
            for (const string &dish : dishes)
                res.back().push_back(to_string(count[{ table, dish }]));
        }
        
        return res;
    }
};