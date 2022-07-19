class Solution {
public:
    vector<int> maxScoreIndices(vector<int> &a) {
        int l0 = 0;
        int r1 = count(a.begin(), a.end(), 1);
        int maxScore = l0 + r1;
        
        for (int i = 0; i < a.size(); i++) {
            l0 += !a[i];
            r1 -= a[i];
            maxScore = max(maxScore, l0 + r1);
        }

        l0 = 0;
        r1 = count(a.begin(), a.end(), 1);
        vector<int> res;
        
        if (l0 + r1 == maxScore)
            res.push_back(0);
        
        for (int i = 0; i < a.size(); i++) {
            l0 += !a[i];
            r1 -= a[i];
            if (l0 + r1 == maxScore)
                res.push_back(i + 1);
        }
        
        return res;
    }
};