class Solution {
public:
    string rearrangeString(string &s, char b, char a) {
        for (int l = 0, r = s.size() - 1; l < r; l++, r--) {
            while (l < r && s[l] != b)
                l++;
            while (l < r && s[r] != a)
                r--;
            swap(s[l], s[r]);
        }
        return s;
    }
};