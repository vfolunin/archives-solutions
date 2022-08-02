class Solution {
public:
    int minimumDeletions(string &s) {
        int lb = 0, ra = count(s.begin(), s.end(), 'a'), res = ra;
        for (int i = 0; i < s.size(); i++) {
            ra -= s[i] == 'a';
            res = min(res, lb + ra);
            lb += s[i] == 'b';
        }
        return res;
    }
};