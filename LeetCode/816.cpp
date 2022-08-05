class Solution {
    string check(const string &whole, const string &frac) {
        if (whole.empty() || whole.size() > 1 && whole[0] == '0')
            return "";
        if (!frac.empty() && frac.back() == '0')
            return "";
        return whole + (frac.empty() ? "" : ".") + frac;
    }
    
public:
    vector<string> ambiguousCoordinates(string &s) {
        s = s.substr(1, s.size() - 2);
        
        vector<string> res;
        
        for (int aSize = 1, bSize = s.size() - 1; aSize < s.size(); aSize++, bSize--) {
            for (int aWholeSize = 1; aWholeSize <= aSize; aWholeSize++) {
                string aWhole = s.substr(0, aWholeSize);
                string aFrac = s.substr(aWholeSize, aSize - aWholeSize);
                string a = check(aWhole, aFrac);
                if (a.empty())
                    continue;
                
                for (int bWholeSize = 1; bWholeSize <= bSize; bWholeSize++) {
                    string bWhole = s.substr(aSize, bWholeSize);
                    string bFrac = s.substr(aSize + bWholeSize);
                    string b = check(bWhole, bFrac);
                    if (b.empty())
                        continue;

                    stringstream ss;
                    ss << "(" << a << ", " << b << ")";
                    res.push_back(ss.str());
                }   
            }
        }
        
        return res;
    }
};