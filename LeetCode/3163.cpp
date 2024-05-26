class Solution {
public:
    string compressedString(string &s) {
        string res;
        for (int l = 0, r = 0; r < s.size(); l = r) {
            while (r < s.size() && r - l + 1 <= 9 && s[l] == s[r])
                r++;
            res += to_string(r - l);
            res += s[l];
        }
        return res;
    }
};