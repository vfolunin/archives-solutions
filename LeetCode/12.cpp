class Solution {
public:
    string intToRoman(int n) {
        static const vector<pair<string, int>> CODES = {
            {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400},
            {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40},
            {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}
        };
        
        string res;
        for (auto &[code, value] : CODES) {
            while (n >= value) {
                n -= value;
                res += code;
            }
        }
        return res;        
    }
};