class Solution {
public:
    string makeAntiPalindrome(string &s) {
        sort(s.begin(), s.end());

        string a = s.substr(0, s.size() / 2);
        string b = s.substr(s.size() / 2);

        int aCommon = 0;
        while (aCommon < a.size() && a[a.size() - 1 - aCommon] == b.front())
            aCommon++;
        
        int bCommon = 0;
        while (bCommon < b.size() && a.back() == b[bCommon])
            bCommon++;
        
        if (aCommon + bCommon > b.size())
            return "-1";
        
        string c = b.substr(bCommon, aCommon);
        string d = b.substr(bCommon + aCommon);
        b = b.substr(0, bCommon);
        return a + c + b + d;
    }
};