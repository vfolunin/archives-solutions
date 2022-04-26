class Solution {
public:
    string freqAlphabets(string s) {
        string res;
        while (!s.empty()) {
            if (s.back() == '#') {
                res += 'a' + stoi(s.substr(s.size() - 3, 2)) - 1;
                for (int i = 0; i < 3; i++)
                    s.pop_back();
            } else {
                res += 'a' + s.back() - '1';
                s.pop_back();
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};