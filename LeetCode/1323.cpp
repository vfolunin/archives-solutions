class Solution {
public:
    int maximum69Number(int n) {
        string s = to_string(n);
        if (int pos = s.find('6'); pos != -1)
            s[pos] = '9';
        return stoi(s);
    }
};