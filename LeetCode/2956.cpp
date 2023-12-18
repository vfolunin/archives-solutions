class Solution {
public:
    vector<int> findIntersectionValues(vector<int> &a, vector<int> &b) {
        int aInB = 0;
        for (int value : a)
            aInB += find(b.begin(), b.end(), value) != b.end();

        int bInA = 0;
        for (int value : b)
            bInA += find(a.begin(), a.end(), value) != a.end();
        
        return { aInB, bInA };
    }
};