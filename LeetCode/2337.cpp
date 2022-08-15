class Solution {
public:
    bool canChange(string &a, string &b) {
        vector<int> aPos;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != '_')
                aPos.push_back(i);
        
        vector<int> bPos;
        for (int i = 0; i < b.size(); i++)
            if (b[i] != '_')
                bPos.push_back(i);
        
        if (aPos.size() != bPos.size())
            return 0;
        
        for (int i = 0; i < aPos.size(); i++)
            if (a[aPos[i]] != b[bPos[i]] ||
                a[aPos[i]] == 'L' && aPos[i] < bPos[i] ||
                a[aPos[i]] == 'R' && aPos[i] > bPos[i])
                return 0;
        
        return 1;
    }
};