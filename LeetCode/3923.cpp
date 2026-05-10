class Solution {
public:
    vector<int> getMiddle(const vector<int> &a, const vector<int> &b) {
        vector<int> m(a.size());
        for (int i = 0; i < m.size(); i++)
            m[i] = (a[i] + b[i]) / 2;
        return m;
    }
    
    int minGenerations(vector<vector<int>> &points, vector<int> &target) {
        set<vector<int>> pointSet(points.begin(), points.end());
        
        for (int i = 0; 1; i++) {
            if (pointSet.count(target))
                return i;

            set<vector<int>> nextPointSet = pointSet;
            for (auto a = pointSet.begin(); a != pointSet.end(); a++)
                for (auto b = next(a); b != pointSet.end(); b++)
                    nextPointSet.insert(getMiddle(*a, *b));

            if (pointSet == nextPointSet)
                return -1;
            
            pointSet.swap(nextPointSet);
        }
    }
};