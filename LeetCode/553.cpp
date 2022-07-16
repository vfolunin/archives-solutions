class Solution {
public:
    string optimalDivision(vector<int> &a) {
        stringstream ss;
        ss << a[0];
        
        if (a.size() > 1) {
            ss << "/";
            
            if (a.size() > 2)
                ss << "(";
            
            for (int i = 1; i < a.size(); i++)
                ss << a[i] << (i + 1 < a.size() ? "/" : "");
            
            if (a.size() > 2)
                ss << ")";
        }
        
        return ss.str();
    }
};