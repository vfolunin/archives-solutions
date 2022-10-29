class Solution {
    int diff(string &a, string &b) {
        int diff = 0;
        for (int i = 0; i < a.size(); i++)
            diff += a[i] != b[i];
        return diff;
    }
    
public:
    vector<string> twoEditWords(vector<string> &queries, vector<string> &dict) {
        vector<string> res;
        
        for (string &a : queries) {
            for (string &b : dict) {
                if (diff(a, b) <= 2) {
                    res.push_back(a);
                    break;
                }
            }
        }
        
        return res;
    }
};