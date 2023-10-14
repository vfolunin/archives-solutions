class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string> &ops) {
        vector<int> values, res;
        int i = 0;
        
        for (string &op : ops) {
            if (op == "prev") {
                i--;
                res.push_back(i >= 0 ? values[i] : -1);
            } else {
                values.push_back(stoi(op));
                i = values.size();
            }
        }
        
        return res;
    }
};