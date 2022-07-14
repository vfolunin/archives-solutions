class Solution {
    string prepare() {
        string s = "122";
        for (int i = 2; s.size() < 1e5; i++)
            s += string(s[i] - '0', '1' + '2' - s.back());
        return s;
    }
    
public:
    int magicalString(int n) {
        static string s = prepare();
        return count(s.begin(), s.begin() + n, '1');
    }
};