class Solution {
public:
    bool isSubsequence(string s, string t) {
        int si = 0;
        for (int ti = 0; si < s.size() && ti < t.size(); ti++)
            if (si < s.size() && s[si] == t[ti])
                si++;
        return si == s.size();
    }
};