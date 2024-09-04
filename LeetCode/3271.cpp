class Solution {
public:
    string stringHash(string &s, int width) {
        string res(s.size() / width, 0);
        for (int i = 0; i < s.size(); i++)
            res[i / width] = (res[i / width] + s[i] - 'a') % 26;
        for (char &c : res)
            c += 'a';
        return res;
    }
};