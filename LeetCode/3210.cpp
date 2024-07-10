class Solution {
public:
    string getEncryptedString(string &s, int shift) {
        rotate(s.begin(), s.begin() + shift % s.size(), s.end());
        return s;
    }
};