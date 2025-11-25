class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        s.erase(remove(s.begin(), s.end(), '0'), s.end());
        if (s.empty())
            s = "0";

        int digitSum = 0;
        for (char c : s)
            digitSum += c - '0';

        return stoll(s) * digitSum;
    }
};