class Solution {
    bool checkDiff(string &a, string &b) {
        int diff = 0;
        for (int i = 0; i < a.size(); i++)
            diff += a[i] != b[i];
        return diff == 1;
    }

    bool checkInsert(string &a, string &b) {
        int prefixSize = 0;
        while (prefixSize < a.size() && a[prefixSize] == b[prefixSize])
            prefixSize++;
        
        int suffixSize = 0;
        while (suffixSize < a.size() && a[a.size() - 1 - suffixSize] == b[b.size() - 1 - suffixSize])
            suffixSize++;
        
        return prefixSize + 1 + suffixSize >= b.size();
    }

public:
    bool isOneEditDistance(string &a, string &b) {
        if (a.size() == b.size())
            return checkDiff(a, b);
        else if (a.size() + 1 == b.size())
            return checkInsert(a, b);
        else if (b.size() + 1 == a.size())
            return checkInsert(b, a);
        else
            return 0;
    }
};