class Solution {
public:
    vector<string> stringSequence(string &target) {
        vector<string> res;
        string s;

        for (int i = 0; s.size() < target.size(); i++) {
            s.push_back('a');
            res.push_back(s);

            while (s[i] != target[i]) {
                s[i]++;
                res.push_back(s);
            }
        }

        return res;
    }
};