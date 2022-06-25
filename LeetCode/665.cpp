class Solution {
public:
    bool checkPossibility(vector<int> &a) {
        if (a.size() == 1)
            return 1;
        
        vector<int> l(a.size());
        for (int i = 0; i < a.size(); i++)
            l[i] = i == 0 || l[i - 1] && a[i - 1] <= a[i];
        
        vector<int> r(a.size());
        for (int i = a.size() - 1; i >= 0; i--)
            r[i] = i == a.size() - 1 || r[i + 1] && a[i] <= a[i + 1];

        if (r[1] || l[a.size() - 2])
            return 1;
        
        for (int i = 1; i + 1 < a.size(); i++)
            if (l[i - 1] && a[i - 1] <= a[i + 1] && r[i + 1])
                return 1;
        
        return 0;
    }
};