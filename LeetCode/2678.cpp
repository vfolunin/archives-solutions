class Solution {
public:
    int countSeniors(vector<string> &a) {
        int res = 0;
        for (string &s : a)
            res += stoi(s.substr(11, 2)) > 60;
        return res;
    }
};