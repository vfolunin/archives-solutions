class Solution {
public:
    string reverseByType(string &s) {
        string a, b;
        for (char c : s) {
            if (islower(c))
                a += c;
            else
                b += c;
        }

        int ai = a.size() - 1, bi = b.size() - 1;
        for (char &c : s) {
            if (islower(c))
                c = a[ai--];
            else
                c = b[bi--];
        }
        return s;
    }
};