class Solution {
public:
    bool repeatedStringMatch(string &a, string &b, int aCount, int bCount) {
        if (a.size() * aCount < b.size() * bCount)
            return 0;
        
        string aa = a;
        for (int i = 1; i < aCount && aa.size() < 300; i++)
            aa += a;
        
        string bb = b;
        if (bCount > 1)
            bb += b;
        
        int index = aa.find(bb);
        return index != -1 && index + b.size() * bCount <= a.size() * aCount;
    }
};