class Solution {
public:
    string convertNumber(string &s) {
        vector<string> digits = {
            "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
        };
        string res;

        for (int i = 0; i < s.size(); ) {
            bool found = 0;
            for (int d = 0; d < digits.size(); d++) {
                if (i + digits[d].size() <= s.size() && s.substr(i, digits[d].size()) == digits[d]) {
                    i += digits[d].size();
                    res += d + '0';
                    found = 1;
                    break;
                }
            }
            if (!found)
                i++;
        }

        return res;
    }
};