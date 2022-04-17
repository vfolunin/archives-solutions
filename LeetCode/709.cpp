class Solution {
public:
    string toLowerCase(string s) {
        for (char &c : s)
            c = tolower(c);
        return s;
    }
};