class Solution {
public:
    vector<int> maxDepthAfterSplit(string &s) {
        vector<int> res(s.size());
        
        vector<int> open;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open.push_back(i);
            } else {
                res[i] = res[open.back()] = open.size() % 2;
                open.pop_back();
            }
        }
        
        return res;
    }
};