class Solution {
public:
    int passwordStrength(string &s) {
        int res = 0;
        for (char c : unordered_set<char>(s.begin(), s.end())) {
            if (islower(c))
                res++;
            else if (isupper(c))
                res += 2;
            else if (isdigit(c))
                res += 3;
            else
                res += 5;
        }
        return res;
    }
};