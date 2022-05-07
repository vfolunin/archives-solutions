class Solution {
public:
    string addStrings(string a, string b) {
        string res;
        for (int ai = a.size() - 1, bi = b.size() - 1, o = 0; ai >= 0 || bi >= 0 || o; ai--, bi--) {
            int aDigit = (0 <= ai && ai < a.size() ? a[ai] - '0' : 0);
            int bDigit = (0 <= bi && bi < b.size() ? b[bi] - '0' : 0);
            int sum = aDigit + bDigit + o;
            res += sum % 10 + '0';
            o = sum / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};