class Solution {
public:
    string nextPalindrome(string &s) {
        string left = s.substr(0, s.size() / 2);
        string mid = s.substr(s.size() / 2, s.size() % 2);

        if (!next_permutation(left.begin(), left.end()))
            return "";
        
        return left + mid + string(left.rbegin(), left.rend());
    }
};