class Solution {
public:
    int minFlips(string &s) {
        int ones = count(s.begin(), s.end(), '1'), cost = 0;
        for (int i = 0; i < s.size(); i++)
            cost += (!i || i == s.size() - 1) ^ (s[i] == '1');
        return min({ ones, (int)s.size() - ones, abs(ones - 1), cost });
    }
};