class Solution {
public:
    string evaluate(string &s, vector<vector<string>> &dictItems) {
        unordered_map<string, string> dict;
        for (vector<string> &item : dictItems)
            dict[item[0]] = item[1];
        
        string res, key;
        bool in = 0;
        
        for (char c : s) {
            if (c == '(') {
                in = 1;
            } else if (c == ')') {
                res += dict.count(key) ? dict[key] : "?";
                key.clear();
                in = 0;
            } else if (in) {
                key += c;
            } else {
                res += c;
            }
        }
        
        return res;
    }
};