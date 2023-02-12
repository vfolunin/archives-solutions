class Solution {
public:
    int countQuadruples(string &a, string &b) {
        vector<int> aPos(26, -1);
        for (int i = a.size() - 1; i >= 0; i--)
            aPos[a[i] - 'a'] = i;
        
        vector<int> bPos(26, -1);
        for (int i = 0; i < b.size(); i++)
            bPos[b[i] - 'a'] = i;
        
        int maxDiff = -1e9;
        for (int i = 0; i < aPos.size(); i++)
            if (aPos[i] != -1 && bPos[i] != -1)
                maxDiff = max(maxDiff, bPos[i] - aPos[i]);
                
        int res = 0;
        for (int i = 0; i < aPos.size(); i++)
            res += aPos[i] != -1 && bPos[i] != -1 && bPos[i] - aPos[i] == maxDiff;
        return res;
    }
};