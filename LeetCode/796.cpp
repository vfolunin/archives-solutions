class Solution {
public:
    bool rotateString(string a, string b) {
        if (a.size() != b.size())
            return 0;
        a += a;
        return a.find(b) != -1;
    }
};