class Solution {
public:
    vector<int> maxDepthAfterSplit(string &s) {
        vector<int> res(s.size());
        
        vector<int> open;
        int depth = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open.push_back(i);
                depth++;
            } else {
                res[i] = res[open.back()] = depth % 2;
                open.pop_back();
                depth--;
            }
        }
        
        return res;
    }
};