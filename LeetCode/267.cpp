class Solution {
    string makePalindrome(string &half, char odd) {
        string res = half;
        if (odd != ' ')
            res += odd;
        res += { half.rbegin(), half.rend() };
        return res;
    }

public:
    vector<string> generatePalindromes(string &s) {
        vector<int> count(26);
        for (char c : s)
            count[c - 'a']++;
        
        char odd = ' ';
        for (int i = 0; i < count.size(); i++) {
            if (count[i] % 2) {
                if (odd == ' ')
                    odd = 'a' + i;
                else
                    return {};
            }
        }

        string half = "";
        for (int i = 0; i < count.size(); i++)
            half += string(count[i] / 2, 'a' + i);

        vector<string> res;
        do {
            res.push_back(makePalindrome(half, odd));
        } while (next_permutation(half.begin(), half.end()));
        return res;
    }
};